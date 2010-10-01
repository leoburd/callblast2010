<?php
/**
 * @file callblast.script.inc
 *  Scripts provided to voipcall nodes by call blast module. 
 */ 

/**
 * Implementation of hook_voipcall_load_script()
 * 
 * @param $script_name 
 *  string
 * 
 * @param $vars, $script_name = 'callblast_message'
 *   $vars = array(
 *     'message_url' => $message_url, 
 *     'forward_to_number' => $forward_to_number,
 *     'options_url' => $options_url,
 *     'one_url' => $one_url,
 *     'two_url' => $two_url,
 *     'three_url' => $three_url,
 *     'four_url' => $four_url,
 *     'five_url' => $five_url,
 *     'six_url' => $six_url,
 *     'seven_url' => $seven_url,
 *     'eight_url' => $eight_url,
 *     'nine_url' => $nine_url,
 *   );  
 * 
 * @param $vars, $script_name = 'callblast_record'
 *  $vars = array('name' => $name, 'number' => $number));
 */
function callblast_voipscript_load_script($script_name, $vars = NULL) {

  $script = NULL;
  switch ($script_name) {
    case 'callblast_message':
      $script = new VoipScript($script_name);
      // start here
      $script->addLabel('start');
      // play main message      
      $text = '';
      $url = $vars['message_url'];
      $timeout = 1;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($text, $url, $timeout, $end_key, $num_digits);

      // If user presses a button during the main message, handle the options
      $script->addGotoIf('process_options', "^%input_digits != '" . VoipScript::NO_INPUT . "'");
      // If no options message provided, hangup
      $script->addGotoIf('end_call', "^!'{$vars['options_url']}'");
      // If the call has been answered by a machine, skip the options and hangup
      $script->addGotoIf('end_call', "^%dial_status == '" . VOIPCALL_ANSWERED_MACHINE . "'");

      // play options
      $script->addLabel('options');
      $text = '';
      $url = $vars['options_url'];
      $timeout = 1;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($text, $url, $timeout, $end_key, $num_digits);

      // process options
      $script->addLabel('process_options');
      // Go to user's selected option.
      // * replay previous message 
      $script->addGotoIf('start', "^%input_digits == '*'");
      // #, end call
      $script->addGotoIf('end_call', "^%input_digits == '#'");
      // 0, go to call forwarding
      $script->addGotoIf('forward', "^(%input_digits == '0') && '{$vars['forward_to_number']}'");
      // go to one 
      $script->addGotoIf('one', "^(%input_digits == '1') && '{$vars['one_url']}'");
      // go to two 
      $script->addGotoIf('two', "^(%input_digits == '2') && '{$vars['two_url']}'");
      // go to three 
      $script->addGotoIf('three', "^(%input_digits == '3') && '{$vars['three_url']}'");
      // go to four
      $script->addGotoIf('four', "^(%input_digits == '4') && '{$vars['four_url']}'");
      // go to five
      $script->addGotoIf('five', "^(%input_digits == '5') && '{$vars['five_url']}'");
      // go to six
      $script->addGotoIf('six', "^(%input_digits == '6') && '{$vars['six_url']}'");
      // go to seven
      $script->addGotoIf('seven', "^(%input_digits == '7') && '{$vars['seven_url']}'");
      // go to eight
      $script->addGotoIf('eight', "^(%input_digits == '8') && '{$vars['eight_url']}'");
      // go to nine
      $script->addGotoIf('nine', "^(%input_digits == '9') && '{$vars['nine_url']}'");
      // If invalid option selected, go back to the options menu
      $script->addSay("Invalid option selected. Please try again.");
      $script->addGoto('options');

      // 0, forward call
      $script->addLabel('forward');
      $script->addSay("Dialing. Please wait.");
      $script->addDial($vars['forward_to_number']);

      // option/message one
      $script->addLabel('one');
      $script->addPlay($vars['one_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message two 
      $script->addLabel('two');
      $script->addPlay($vars['two_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message three 
      $script->addLabel('three');
      $script->addPlay($vars['three_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message four 
      $script->addLabel('four');
      $script->addPlay($vars['four_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message five 
      $script->addLabel('five');
      $script->addPlay($vars['five_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message six
      $script->addLabel('six');
      $script->addPlay($vars['six_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message seven
      $script->addLabel('seven');
      $script->addPlay($vars['seven_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message eight
      $script->addLabel('eight');
      $script->addPlay($vars['eight_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // option/message nine
      $script->addLabel('nine');
      $script->addPlay($vars['nine_url']);
      // go back to "options" menu
      $script->addGoto('end_call');

      // end call (hang up)
      $script->addLabel('end_call');
      $script->addHangup();    
    
    break;

    case 'callblast_record': 
      $script = new VoipScript('callblast_record');

      $script->addLabel('start');
      $script->addSay("Please record your message after the beep.  When done, press the pound key.");
      $timeout = 5;
      $end_key = '#';
      $max_length = 20;
      $script->addRecord($timeout, $end_key, $max_length);

      $script->addSay('You said ');
      $script->addPlay('%recording_url');

      $script->addLabel('accept menu');
      $text = "To accept this recording, press 1.  To record it once again, press 2. To hangup, press the pound key.";
      $url = '';
      $timeout = 5;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($text, $url, $timeout, $end_key, $num_digits);

      $script->addGotoIf('accept recording', "^%input_digits == '1'");

      $script->addGotoIf('start', "^%input_digits == '2'");

      $script->addGotoIf('end call', "^%input_digits == '#'");

      $script->addSay('Invalid input received. Please try again.');
      $script->addGoto('accept menu');

      $script->addLabel('accept recording');
      $script->addSay('About to start processing the recorded file.');
      // Set variables from $vars to pass to callback function.
      $script->addSet('uid', $vars['uid']); 
      $script->addSet('name', $vars['name']); 
      $script->addSet('number', $vars['number']); 
      // Process recording.
      $script->addSet('callback_result',
        '^_callblast_record_callback(%call_id, %recording_url, %recording_duration, %uid, %name, %number)');

      $script->addSay('The callback returned: %callback_result');
      $script->addGoto('end call');

      $script->addLabel('no input received');
      $script->addSay("No input received. Please try again.");
      $script->addGoto('start');

      $script->addLabel('end call');
      $script->addSay('Bye bye.');
      $script->addHangup();

    break;
  }

  return $script;
}

/**
 * Callback for the voip script callblast_record.
 * 
 * @see hook_voipscript_load_script()
 */
function _callblast_record_callback($call_id, $recording_url, $recording_duration, $uid, $name, $number) {
  // Note: Do not replace $call_id and $recording_url with '%s' here, it will cause mysql errors.
  $sql = "INSERT INTO {callblast_recording} (call_id, url, uid, name, number, duration) " 
          ."VALUES ('$call_id', '$recording_url', %d, '%s', '%s', %d) ";
  $args = array($uid, $name, $number, $recording_duration);
  db_query($sql, $args);

 // Log call blast with watchdog
  $type = 'call blast';
  $message = t("New message recorded. Call_id: $call_id, recording_url: $recording_url, recording_duration: $recording_duration, name: $name, number: $number, uid: $uid");
  $severity = WATCHDOG_NOTICE;
  watchdog($type, $message);

  return 'Success.';
}

