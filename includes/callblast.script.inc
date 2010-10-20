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
      // If the call has been answered by a machine and we have an alternate 
      // message for answering machines, play it.
      $script->addGotoIf('start', "^%dial_status != '" . VOIPCALL_ANSWERED_MACHINE . "'"); 
      $machine_message = $vars['machine_message'];
      $is_machine = ($machine_message) ? 'TRUE' : 'FALSE';  
      $script->addGotoIf('start', "^!$is_machine");
      $script->addPlay($machine_message);
      $script->addHangup();

      // play options
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
      $script->addGotoIf('hang_up', "^!'{$vars['options_url']}'");
      // If the call has been answered by a machine, skip the options and hangup
      $script->addGotoIf('hang_up', "^%dial_status == '" . VOIPCALL_ANSWERED_MACHINE . "'");

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
      // save input
      // note: callblast_input variable isn't used. we just want to call _callblast_input().
      $script->addSet('callblast_input', '^_callblast_input(%input_digits, %call_id)');
      // Go to user's selected option.
      // * replay previous message 
      $script->addGotoIf('start', "^%input_digits == '*'");
      // #, end call
      $script->addGotoIf('hang_up', "^%input_digits == '#'");
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
      // end call
      $script->addGoto('end_call');

      // option/message two 
      $script->addLabel('two');
      $script->addPlay($vars['two_url']);
      // end call
      $script->addGoto('end_call');

      // option/message three 
      $script->addLabel('three');
      $script->addPlay($vars['three_url']);
      // end call
      $script->addGoto('end_call');

      // option/message four 
      $script->addLabel('four');
      $script->addPlay($vars['four_url']);
      // end call
      $script->addGoto('end_call');

      // option/message five 
      $script->addLabel('five');
      $script->addPlay($vars['five_url']);
      // end call
      $script->addGoto('end_call');

      // option/message six
      $script->addLabel('six');
      $script->addPlay($vars['six_url']);
      // end call
      $script->addGoto('end_call');

      // option/message seven
      $script->addLabel('seven');
      $script->addPlay($vars['seven_url']);
      // end call
      $script->addGoto('end_call');

      // option/message eight
      $script->addLabel('eight');
      $script->addPlay($vars['eight_url']);
      // end call
      $script->addGoto('end_call');

      // option/message nine
      $script->addLabel('nine');
      $script->addPlay($vars['nine_url']);
      // end call
      $script->addGoto('end_call');

      // end call 
      $script->addLabel('end_call');
      // If no pre-end message provided, hang up
      $script->addGotoIf('hang_up', "^!'{$vars['pre_end']}'");
      // play pre_end message and get input
      $text = ''; 
      $url = $vars['pre_end'];
      $timeout = 1;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($text, $url, $timeout, $end_key, $num_digits);
      // If user presses 0, go to call forwarding
      $script->addGotoIf('forward', "^(%input_digits == '0') && '{$vars['forward_to_number']}'");
      // If user presses * replay previous message 
      $script->addGotoIf('options', "^%input_digits == '*'");
      // If user presses #, hang up
      $script->addGotoIf('hang_up', "^%input_digits == '#'");
      // hang up 
      $script->addHangup();    

      // hang up 
      $script->addLabel('hang_up');
      $script->addHangup();    
    
    break;

    case 'callblast_record': 
      $script = new VoipScript('callblast_record');

      $script->addLabel('start');
      $script->addSay("Please record your message after the beep.  When done, press the pound key.");
      $timeout = 5; 
      $end_key = '#';
      $max_length = 3600;// max recording time 1 hour (Twilio will end after 5 second pause if user doesn't end recording).
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

      $script->addSay('Invalid input. Please try again.');
      $script->addGoto('accept menu');

      $script->addLabel('accept recording');
      //$script->addSay('About to start processing the recorded file.');
      // Set variables from $vars to pass to callback function.
      $script->addSet('uid', $vars['uid']); 
      $script->addSet('name', $vars['name']); 
      $script->addSet('number', $vars['number']); 
      // Process recording.
      $script->addSet('callback_result',
        '^_callblast_record_callback(%call_id, %recording_url, %recording_duration, %uid, %name, %number)');

      $script->addSay('%callback_result');
      $script->addGoto('end call');

      $script->addLabel('no input received');
      $script->addSay("No input received. Please try again.");
      $script->addGoto('start');

      $script->addLabel('end call');
      $script->addSay('Goodbye.');
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
  $message = t("New message recorded. Call_id: $call_id, recording_url: $recording_url, "
              ."recording_duration: $recording_duration, name: $name, number: $number, uid: $uid");
  $severity = WATCHDOG_NOTICE;
  watchdog($type, $message);

  return 'Thank you.';
}

/**
 * Callback for the voip script callblast_message
 * to record user input.
 * 
 * @param $input_digits
 *  integer, button pressed
 * 
 * @param $call_id
 *  string, unique call id (can be used to match call to voipcall node)
 * 
 * @return
 *  boolean
 */
function _callblast_input($input_digits, $call_id) {
  // save user input to input table
  db_query("INSERT INTO {callblast_input} (call_id, input_digits) " 
          ."VALUES ('$call_id', '$input_digits') ");

 // Log input from call blast with watchdog
  $type = 'call blast';
  $message = t("call_id: $call_id, input_digits: $input_digits");
  $severity = WATCHDOG_NOTICE;
  watchdog($type, $message);
  
  if ($input_digits && $call_id) {
    return TRUE;
  }
}
