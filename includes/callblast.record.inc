<?php
/**
 * @file callbblast.record.inc
 *  callback for callblast/record
 */
/**
 * callblast_record_form form 
 *
 * @return $form
 *  array, see Form API
 */
function callblast_record_form() {
  $form['callblast']['name'] = array(
    '#type' => 'textfield', 
    '#title' => t('Message Name'), 
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => TRUE,
    '#description' => t('Give this message a name.'),
  );  
  $form['callblast']['number'] = array(
    '#type' => 'textfield', 
    '#title' => t('Phone Number'), 
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => TRUE,
    '#description' => t('Please enter a phone number. When you click '
                       .'Submit, you will receive a call at this number. '
                       .'Follow the prompt to record your message.'),
  );  
  $form['callblast']['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Submit'), 
  );  
  return $form; 
}

/**
 * Callback for form submission.
 * 
 * TODO Should we give users a way to delete bad messages? 
 */ 
function callblast_record_form_submit(&$form, &$form_state) {
//dsm($form_state);
  global $user;

  $name = $form_state['values']['name'];
  $number = $form_state['values']['number'];
  $vars = array('uid' => $user->uid, 'name' => $name, 'number' => $number);

  // Create new voipcall node for the call 
  // that's about to be placed to the user 
  // recording a callblast message.
  $details['dest_number'] = $number;
  $details['dest_name'] = $user->name;
  $details['caller_name'] = 'callblast message recorder';
  // load voip script
  $script = VoipScript::loadScript('callblast_record', $vars);
  $details['script'] = $script;
  $voipcall_node = voipcall_save($details); 

  // Dial the call.
  voip_dial($voipcall_node);

  // Store message name, number, uid, and url for recorded message in database.
//TODO

  // Log call blast with watchdog
  $type = 'call blast';
  $message = t("New call blast message recorded by $user->name. See voipcall nid $voipcall_node->nid");
  $severity = WATCHDOG_NOTICE;
  watchdog($type, $message);
}


