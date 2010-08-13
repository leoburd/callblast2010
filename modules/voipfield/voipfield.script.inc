<?php
/**
 * @file voip.script.inc
 *  script for recording messages by phone
 */

/**
 * Implementation of hook_voipcall_load_script()
 */
function voipfield_voipcall_load_script($voipcall, $script_name) {
  if($script_name == 'voipfield_record') {
    $script = array();
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_LABEL,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'start'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAL => t("Please record your message after the beep.  When done, press the pound key.")),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_RECORD,
      VOIPCALL_CMD_BODY => array(
        'max_length' => array(VOIPCALL_VAL => '20'),
        'end_key' => array(VOIPCALL_VAL => '#'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAL => "You said "),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_PLAY,
      VOIPCALL_CMD_BODY => array(
        'url' => array(VOIPCALL_VAR => 'recording_url'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_LABEL,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'accept menu'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_GATHER,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAL => t("To accept this recording, press 1.  To record it once again, press 2. To hangup, press the pound key.")),
        'num_digits' => array(VOIPCALL_VAL => 1),
        'end_key' => array(VOIPCALL_VAL => ""),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_GOTOIF,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'accept recording'),
        // Note: variable names have to be enclosed in between '@<'and '>@'
        'expression' => array(VOIPCALL_EVAL => "@<gather_digits>@ == '1'"),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_GOTOIF,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'start'),
        // Note: variable names have to be enclosed in between '@<'and '>@'
        'expression' => array(VOIPCALL_EVAL => "@<gather_digits>@ == '2'"),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_GOTOIF,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'end call'),
        // Note: variable names have to be enclosed in between '@<'and '>@'
        'expression' => array(VOIPCALL_EVAL => "@<gather_digits>@ == '#'"),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAL => "Invalid input received. Please try again."),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_GOTO,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'accept menu'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_LABEL,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'accept recording'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAL => "About to start processing the recorded file."),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SET,
      VOIPCALL_CMD_BODY => array(
        'var_name' => array(VOIPCALL_VAL => "callback result"),
        // NOTE: Do not add a ';' at the end of the function call.  That will result in a runtime error.
        'var_value' => array(VOIPCALL_EVAL => "voiptest_record_callback(@<call_id>@, @<recording_url>@, @<recording_duration>@)"),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAL => "The callback returned: "),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAR => "callback result"),
      ),
    );

    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_HANGUP,
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_LABEL,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'no input received'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
        'text' => array(VOIPCALL_VAL => "No input received. Please try again."),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_GOTO,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'start'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_LABEL,
      VOIPCALL_CMD_BODY => array(
        'label_name' => array(VOIPCALL_VAL => 'end call'),
      ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_SAY,
      VOIPCALL_CMD_BODY => array(
       'text' => array(VOIPCALL_VAL => "Bye bye."),
       ),
    );
    $script[] = array(
      VOIPCALL_CMD_ID => VOIPCALL_HANGUP
    );

  }

  return $script;
}


/**
 * Callback function associated with the script voiptest_record.  It is called whenever that script records a new entry from the user.
 */
function voipfield_record_callback($call_id, $recording_url, $recording_duration=NULL) {
watchdog('voipfield', "in voipfield_record_callback($call_id, $recording_url, $recording_duration)");

  return TRUE;
}
