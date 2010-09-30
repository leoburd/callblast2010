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
 */ 
function callblast_record_form_submit(&$form, &$form_state) {
//dsm($form_state);
 
  $name = $form_state['values']['name'];
  $number = $form_state['values']['number'];

//dsm(array('name' => $name, 'number' => $number));

  // load voip script
// CONTINUE HERE
// CREATE CALLBLAST_RECORD SCRIPT
  //$script = VoipScript::loadScript('callblast_record', $vars);
  //$details['script'] = $script;

  // Fill in $details for voipcall_save().

  // Send call to number with voipcall_save($details); 
  // TODO It's not intuitive that voipcall_save is how you send a call out.
  // Store message name, number, uid, and url for recorded message in database.
}
