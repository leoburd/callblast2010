<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function callblast_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_advanced
  $groups['callblast-group_advanced'] = array(
    'group_type' => 'standard',
    'type_name' => 'callblast',
    'group_name' => 'group_advanced',
    'label' => 'Advanced Call Blast Settings',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsed',
        'description' => '',
      ),
      'display' => array(
        'weight' => '2',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '2',
    'fields' => array(
      '0' => 'field_callblast_script',
    ),
  );

  // Exported group: group_options
  $groups['callblast-group_options'] = array(
    'group_type' => 'standard',
    'type_name' => 'callblast',
    'group_name' => 'group_options',
    'label' => 'Additional Voice Message Options',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsed',
        'description' => '<p>The <strong>Options Message</strong> offers the callee options, then records and responds to their options. For example, this message might say: "For if you can attend the meeting in Boston press 1, if you can attend the meeting in New York City press 2, if you would like to organize a meeting in you own city or town press 3." The button pushed will be recorded for each call, and <a href="/?q=callstatus">available for you to review.</a></p>
<p><strong>Button X message</strong> provides a response to the callee\'s selection. For example, Button 1 message might say something like this: "The Boston meeting will take place at MIT, June 1, 2010. To get to MIT... "</p>
<p><strong>Suggestion:</strong> As a courtesy to the callee, you may want to end each recording with this sentence: "To replay this recording press *, to speak with someone in person press 0 and to disconnect press #."</p>',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '1',
    'fields' => array(
      '0' => 'field_callblast_audio_options',
      '1' => 'field_callblast_audio_one',
      '2' => 'field_callblast_audio_two',
      '3' => 'field_callblast_audio_three',
      '4' => 'field_callblast_audio_four',
      '5' => 'field_callblast_audio_five',
      '6' => 'field_callblast_audio_six',
      '7' => 'field_callblast_audio_seve',
      '8' => 'field_callblast_audio_eigh',
      '9' => 'field_callblast_audio_nine',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Voice Message Options');
  t('Advanced Call Blast Settings');

  return $groups;
}
