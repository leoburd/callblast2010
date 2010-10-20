<?php 
/**
 * @file callblast.inc
 *  Business logic of Call Blast module.
 * 
 *  This is custom code. The functions here
 *  are not hooks provided by Drupal or contributed
 *  modules.  This code was not written by the 
 *  Features module.
 */

/**
 * Callback for callblast/list/autocomplete
 * to autocomplete call list field on 
 * node/add/callblast and node/edit/% forms.
 */
function callblast_list_autocomplete() {
  $items = array();
  $items = module_invoke_all('callblast_list');
  asort($items);
  foreach ($items as $key => $value) {
    $readable = $value .'  ((('. $key .')))';
    $list[$readable] = $value;
  }
  print drupal_to_js($list);
  exit();
}

/**
 * Implementation of hook_voip_get_script().
 */
// TODO Delete? Is this still useful for anything? Cruft? 
function callblast_voip_get_script() {
  // TODO: this function should return callblast-specific scripts.  The "hello_world" script has already been defined by voip_tester.module
  // NOTE: How to name scripts? <module_prefix>_name.xml? Do we need the .xml?
  // NOTE: the following require once should assign the script to a variable and return that variable
  require_once('hello_world.xml');
}

/**
 * Convert a list name to a machine-readable
 * text id, consisting only of numbers, lowercase  
 * letters and underscores.
 */
function callblast_id($module, $name) {
  $id = $module .'_'. $name;  

  // make lowercase
  $id = strtolower($id);

  // Replace space with _
  $pattern = '/ /';
  $replacement = '_';
  $id = preg_replace($pattern, $replacement, $id);

  // Replace - with _
  $pattern = '/-/';
  $replacement = '_';
  $id = preg_replace($pattern, $replacement, $id);

  // Replace !#$%&'*+/=?^`{|}~@.[] 
  $pattern = '([!#$%&\'*+/=?^`{|}~@.\[\]\:<>;])';
  $replacement = '';
  $id = preg_replace($pattern, $replacement, $id);

  // incase we missed anything weird
  $id = filter_var($id, FILTER_SANITIZE_STRING);

  return $id;
}

/**
 * Callblack for #default_value.
 * Make it human readable.
 * 
 * todo Add error handling to check for two lists with the same id and then throw an error message. 
 */
function callblast_list_default($value) {
  $title = module_invoke_all('callblast_get_title', $value);  
  if ($title[0]) {
    return $title[0] .'  ((('. $value .')))';
  } 
}

/**
 * Callblack for formatting Call List title as
 * human readable, without showing calllist ID. 
 * Make it human readable.
 * 
 * todo Add error handling to check for two lists with the same id and then throw an error message. 
 */
function callblast_list_title($value) {
  $title = module_invoke_all('callblast_get_title', $value);  
  if ($title[0]) {
    return $title[0];
  } 
}

/**
 * Invoke hook_callblast_get_list to get 
 * the numbers on the list from the module 
 * (or, modules if there are more than one)
 * that provided it.
 * 
 * @param
 *  $node object
 * 
 * @return
 *  string, callblast list selected on callblast node.
 */
function callblast_list($node) {
  $list_name = check_plain($node->field_callblast_calllist[0]['value']);
  $list = module_invoke_all('callblast_get_list', $list_name);

  return $list;
}

/**
 * @param
 *  $list, an array of numbers to be called. 
 * 
 * @param
 *  $node, object, a callblast node.
 */
function callblast_save_voipcalls($list, $node) {
  global $base_url;

  // generic call details from callblast node
  $details['caller number'] = $node->field_callblast_caller_number[0]['value'];
  $details['caller name'] = $node->field_callblast_caller_name[0]['value'];
  $details['parent node'] = $node->nid; // TODO delete?
  $details['scheduled start'] = $node->field_callblast_scheduled_start[0]['value'];
 
  // Get variables to pass to script. (URLs of messages to be played.)
  $vars = _callblast_message_vars($node);
  
  // load voip script
  $script = VoipScript::loadScript('callblast_message', $vars);
  $details['script'] = $script;

  // save up voipcall nodes from $list
  $i = 0;
  $count = count($list);
  while ($i < $count) {
    if ($list[$i]['destination']) {
      $details['dest_number'] = $list[$i]['destination'];
      $details['dest_name'] = $list[$i]['name'];
      // save voipcall node
      $voipcall_node = voipcall_save($details);
      // store callblast_nid,  voipcall_nid pairs and call status in callblast_call table
      $callblast_call->voipcall_nid = $voipcall_node->nid; 
      $callblast_call->callblast_nid = $node->nid;
      $callblast_call->status = 'queued';
      callblast_set_call_status($callblast_call); 
    } else {
      // no destination number
      // TODO Add validation/error handling here. 
      //   Right now we're just checking for something or nothing. 
      //   But, for example, a 6 digit phone number should trigger an error too.
      drupal_set_message(t('Invalid destination number on call list.'), 'warning');
    }
    $i++;
  }
}

/**
 * Send scheduled call blasts.
 */
function callblast_run() {
  // Check for call blasts that have been scheduled but not sent.
  $sql = "SELECT n.nid, n.vid " 
        ."FROM {node} n " 
        ."JOIN {content_type_callblast} cb ON n.nid = cb.nid "
        ."WHERE field_blast_sent_value = 0 "
        ."OR ISNULL(field_blast_sent_value) ";
  $result = db_query($sql);

  // @todo these should be added to a queue. Lots of big lists could get messy.
  // loop through unblasted blast lists and blast them
  while ($row = db_fetch_object($result)) {
    $callblast_nid = $row->nid;
    $callblast_vid = $row->vid;
  
    // Check when call is scheduled to get sent. 
    // Skip if it's scheduled for later.
    // @todo Performance could probably be improved by using litenode for the query above and skipping the node_load here. 
    $node = node_load($callblast_nid);
    $start_time =  $node->field_callblast_scheduled_start[0]['value'];
    // TODO Add timezone handling.
    // $timezone = $node->field_callblast_scheduled_start[0]['timezone'];
    $now = time();
    if ($start_time <= $now) {
      callblast_send($node);
    } // end if ($start_time <= $now)
  } // end while
  return TRUE;
}

/**
 * Send call blast (blast calls our 
 * to all the numbers on this call blast list).
 * 
 * @param
 *  $node, callblast node object.
 */
function callblast_send($node) {
  // Save call blast start time.
  $node->field_callblast_start[0]['value'] = time();

  // Get selected call list.
  $list = callblast_list($node);
  // Save call list. (Each number on list must
  // be stored as a voipcall node.)
  callblast_save_voipcalls($list, $node);

  // get list of voipcall nids 
  // voip.module gets the phone numbers from the voipcall node
  $callblast_nid = $node->nid;
  $callblast_vid = $node->vid;
  $queue_size = variable_get('callblast_queue_size', 10);
  $sql = 'SELECT voipcall_nid FROM {callblast_call} WHERE callblast_nid = %d LIMIT %d '; 
  $result2 = db_query($sql, $callblast_nid, $queue_size);

  // place phone calls to each number on the list, one-by-one
  while ($voipcall_nid = db_result($result2)) { 
    _callblast_call($callblast_nid, $voipcall_nid);
  }
  
  // Record callblast as sent.
// TODO QUEUE: Record callblast as "sending" 
// TODO QUEUE: Also, add a kill switch.
  $node->field_blast_sent[0]['value'] = 1;
  // Save callblast end time.
  // (What time the callblast was completed.)
// TODO PREP QUEUE: Replace boolean callblast status field with values like 'sending', 'not sent', 'complete'. (maybe make it an integer field?)
// TODO QUEUE (move this to QUEUE 5): Note this end time is missleading. This is the end of cron kicking off the callblast. But the calls haven't been finished yet. They've just all been sent to voip. E.g. see http://whatsupserver.media.mit.edu/cfk/node/447, this looks like the call blast started and ended at 11:38am, but the blast actually sent over a period of 3-6 minutes.
  $node->field_callblast_end[0]['value'] = time();
  node_save($node);

  // Log call blast with watchdog
  $type = 'call blast';
  $message = t("Call blast nid-$callblast_nid sent.");
  $severity = WATCHDOG_NOTICE;
  watchdog($type, $message);
}

/**
 * Wrapper around callblast_send() for 
 * "Send Now" button on callblast node edit forms.
 */
function _callblast_send_now($form, $form_state) {
  $node = node_load($form_state['nid']);
  callblast_send($node);
}

/**
 * Place an individual call to 
 * the specified number (this is one of 
 * the numbers on the call blast list 
 * that is currently being called by callblast_send().
 * 
 * @param
 *  $callblast_nid, integer, node id of the callblast sending voipcall
 *  $voipcall_nid, integer, node id of the voipcall 
 *  node to be sent.
 */
function _callblast_call($callblast_nid, $voipcall_nid) {
  $voipcall_node = node_load($voipcall_nid);    
  // set call status to 'calling'
  $callblast_call->voipcall_nid = $voipcall_nid;
  $callblast_call->callblast_nid = $callblast_nid; 
  $callblast_call->status = 'calling';
  $callblast_call->update = TRUE; 
  callblast_set_call_status($callblast_call);
  // place outgoing call
  voip_dial($voipcall_node);
}

/**
 * @return 
 *  array, $recordings
 *  - $recordings[n]['name'] => $message_name; 
 *  - $recordings[n]['url'] => $url;
 *  - $recordings[n]['number'] => $url;
 *  - $recordings[n]['duration'] => $url;
 *  - $recordings[n]['uid'] => $url;
 */
function callblast_get_recordings() {
  $results = db_query("SELECT * FROM {callblast_recording} ");
  $recordings = array();
  $i = 0;
  while ($row = db_fetch_object($results)) {
    $recordings[$i]['name'] = $row->name; 
    $recordings[$i]['url'] = $row->url;
    $recordings[$i]['number'] = $row->number;
    $recordings[$i]['duration'] = $row->duration;
    $recordings[$i]['uid'] = $row->uid;
    $i++;
  }

  return $recordings;
}

/**
 * @param $nid
 *  integer, voicall node id
 * 
 * @return
 *  array, input digits in the order they were pushed by a listener during a call blast.
 */
function callblast_get_input($nid) {
  $results = db_query("SELECT input_digits FROM {callblast_input} "
                     ."WHERE voipcall_nid = %d "
                     ."ORDER BY input_id ASC ", $nid );
  $input = array();
  while ($row = db_fetch_object($results)) {
    $input[] = $row->input_digits;
  } 
  return $input;
}

/**
 * @param $node
 *  object, callblast node (this is the callblast being sent)
 * 
 * @return $vars
 *  array, variables to be passed to voip script when the script is loaded
 *  Specifically, URLs of messages to be played.
 */
function _callblast_message_vars($node) {
  global $base_url;

  // call forwarding number
  $forward_to_number = $node->field_callblast_call_forward[0]['value']; 

  // options
  $upload = $node->field_callblast_upload_ops[0]['filepath'];
  $recording = $node->field_callblast_recording_ops[0]['value'];
  $options_url = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 

  // answering machine message 
  $upload = ''; // todo this field doesn't exist yet
  $recording = $node->field_callblast_recording_machin[0]['value'];
  $machine_message = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 

  // pre-end
  $upload = $node->field_callblast_upload_preend[0]['filepath']; // todo this field doesn't exist yet
  $recording = $node->field_callblast_recording_preend[0]['value'];
  $pre_end = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 

  $message_url = array();
  // main message
  $upload = $node->field_callblast_upload0[0]['filepath']; 
  $recording = $node->field_callblast_recording0[0]['value']; 
  $message_url[0] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 1
  $upload = $node->field_callblast_upload1[0]['filepath']; 
  $recording = $node->field_callblast_recording1[0]['value']; 
  $message_url[1] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 2
  $upload = $node->field_callblast_upload2[0]['filepath']; 
  $recording = $node->field_callblast_recording2[0]['value']; 
  $message_url[2] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 3
  $upload = $node->field_callblast_upload3[0]['filepath']; 
  $recording = $node->field_callblast_recording3[0]['value']; 
  $message_url[3] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 4
  $upload = $node->field_callblast_upload4[0]['filepath']; 
  $recording = $node->field_callblast_recording4[0]['value']; 
  $message_url[4] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 5
  $upload = $node->field_callblast_upload5[0]['filepath']; 
  $recording = $node->field_callblast_recording5[0]['value']; 
  $message_url[5] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 6
  $upload = $node->field_callblast_upload6[0]['filepath']; 
  $recording = $node->field_callblast_recording6[0]['value']; 
  $message_url[6] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 7
  $upload = $node->field_callblast_upload7[0]['filepath']; 
  $recording = $node->field_callblast_recording7[0]['value']; 
  $message_url[7] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 8
  $upload = $node->field_callblast_upload8[0]['filepath']; 
  $recording = $node->field_callblast_recording8[0]['value']; 
  $message_url[8] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 
  // button 9
  $upload = $node->field_callblast_upload9[0]['filepath']; 
  $recording = $node->field_callblast_recording9[0]['value']; 
  $message_url[9] = ($upload)? $base_url.'/'.drupal_urlencode(check_url($upload)) : $recording; 

  $vars = array(
    // main message
    'message_url' => $message_url[0], 
    // answering machine message
    'machine_message' => $machine_message,
    // forwarding number (when user hits 0)
    'forward_to_number' => $forward_to_number,
    // options
    'options_url' => $options_url,
    // pre end
    'pre_end' => $pre_end,
    // button 1
    'one_url' => $message_url[1],
    // button 2
    'two_url' => $message_url[2],
    // button 3
    'three_url' => $message_url[3],
    // button 4
    'four_url' => $message_url[4],
    // button 5
    'five_url' => $message_url[5],
    // button 6
    'six_url' => $message_url[6],
    // button 7
    'seven_url' => $message_url[7],
    // button 8
    'eight_url' => $message_url[8],
    // button 9
    'nine_url' => $message_url[9],
  );

  return $vars;
}

/**
 * Set call status for callblast calls in callblast_call table.
 * 
 * @param 
 * $callblast_call, object
 * - $callblast_call->voipcall_nid, int, the nid of the voipcall being added/updated
 * - $callblast_call->callblast_nid, int, the nid of the callbalst being sent
 * - $callblast_call->status, string, 'queued', 'calling', 'completed', 'canceled'
 * - $callblast_call->update, boolean
 * 
 * Call status descriptions: 
 * - 'queued' - callblast is running, this call is in the queue to get sent
 * - 'calling' - call has been sent to voip server, too late to cancel it
 * - 'completed' - call went out and has been completed
 * - 'canceled' - call was queued then canceled before it went out
 */ 
function callblast_set_call_status($callblast_call) {
  if (!$callblast_call->update) {
    // New voipcall
    drupal_write_record('callblast_call', $callblast_call);
  } else if ($callblast_call->update) {
    // Update existing voipcall. Specify primary keys.
    $update = array('voipcall_nid', 'callblast_nid'); 
    drupal_write_record('callblast_call', $callblast_call, $update);
  }
}

/**
 * @param $voipcall_nid
 *  int, node id of voipcall
 * 
 * @return $callblast_nid
 *  int, node id of callblast this voipcall belongs to
 */
function callblast_get_callblast_nid($voipcall_nid) {
  $sql = "SELECT callblast_nid FROM {callblast_call} WHERE voipcall_nid = %d ";
  $callblast_nid = db_result(db_query($sql, $voipcall_nid));
  if ($callblast_nid) {
    return $callblast_nid; 
  } else {
    return FALSE; 
  }
}

/**
 * As calls get completed one-by-one, 
 * check for queued calls and  kick off the next call
 * one-by-one.
 * 
 * @param $callblast_nid
 *  int, node id of callblast being sent
 */
function callblast_send_next_call($callblast_nid) {
  // Check queue size.
  $queue_size = variable_get('callblast_queue_size', 10);
  // Check how many calls are currently being called.
  $sql = "SELECT COUNT(voipcall_nid) as active_calls FROM {callblast_call} WHERE status = 'calling' ";   
  $active_calls = db_result(db_query($sql));
  // Kick off the next call?...
  if ($queue_size > $active_calls) {
    // Get queued voipcall_nid.
    $sql = "SELECT voipcall_nid FROM {callblast_call} WHERE callblast_nid = %d AND status = 'queued' LIMIT 1 ";
    $voipcall_nid = db_result(db_query($sql, $callblast_nid));
    // Send the next call.
    _callblast_call($callblast_nid, $voipcall_nid);
  }

//TODO QUEUE 5. When there are no more calls in the queue, set callblast to "complete", set end time for callblast here.  
}
