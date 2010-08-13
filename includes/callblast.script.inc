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
 * @param $vars
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
 */
function callblast_voipscript_load_script($script_name, $vars) {

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
  }

  return $script;
}
