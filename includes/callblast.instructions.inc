<?php
/**
 * @file callblast.instructions.inc
 *  provide content of instructions page 
 */
/**
 * 
 */
function callblast_instructions_page() {
  $output = '';

  $steps = array();
  $i = 0;

  $intro = t('Welcome to the Call Blast tool');

// TODO take HTML out of t() functions.
  $i++; 
  $steps[$i]['title'] = t('Record call blast message(s).'); 
  $steps[$i]['path'] = 'callblast/record';
  $steps[$i]['description'] = t('
      A call blast can include between one and eleven recorded messages:<br/>
     <strong>Main Message</strong> - This is the first message that plays when someone answers the phone. All call blasts must have a main message. All other messages are optional. <br/>
     <strong>Options Message</strong> - If you are going to do anything besides simply play a single message, you need an "Options" message. The options message should prompt the listener to press one of the keys on the dial pad to hear another message, be forwarded to another number, start over, or end the call. It should be something like this, <em>"For directions press 1, to hear about other events press 2,..."</em> etc. The end of the message should say, <em>"To start over press *, to hang-up press #, or to be connected to [the designated forwarding number] press 0."</em><br/>
      <strong>Button 1 message recording</strong> - Message to be played when listener presses 1 on the phone dial pad.<br/>
      <strong>Button 2 message recording</strong> - Message to be played when listener presses 2 on the phone dial pad.<br/>
      <strong>etc...</strong><br/>
      <strong>Button 9 message recording</strong> - Message to be played when listener presses 9 on the phone dial pad.<br/>
      <strong>Buttons *, #, 0</strong> - These are special buttons. See <em>Options Message</em> for details.<br/><br/>
  ');

  $i++; 
  $steps[$i]['title'] = t('Create a call list.');
  $steps[$i]['path'] = 'node/add/calllist';
  $steps[$i]['description'] = t('Enter or upload a list of phone numbers to call.<br/><br/>');

  $i++; 
  $steps[$i]['title'] = t('Create a call blast.');
  $steps[$i]['path'] = 'node/add/callblast';
  $steps[$i]['description'] = t('Create a call blast to send now, or to be sent at a later date.<br/><br/>');

  $i++; 
  $steps[$i]['title'] = t('Review/Revise an existing call blast.');
  $steps[$i]['path'] = 'node/add/callblast';
  $steps[$i]['description'] = t('Edit existing call blasts or review the status of calls from call blasts that have already been sent.<br/><br/>');

// TODO put this in a theme function.
  $output .= $intro;
  $output .= '<ol>';
  foreach ($steps as $step) {
    $link = l($step['title'], $step['path']);
    $description = $step['description'];
    $output .= "<li><h3>$link</h3>$description</li>";
  }
  $output .= '</ol>';

  return $output;
}
