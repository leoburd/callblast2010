<?php

/**
 * Implementation of hook_content_default_fields().
 */
function callblast_content_default_fields() {
  $fields = array();

  // Exported field: field_blast_sent
  $fields['callblast-field_blast_sent'] = array(
    'field_name' => 'field_blast_sent',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|
1|Blast sent',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Blast sent',
      'weight' => '6',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_callblast_audio_eigh
  $fields['callblast-field_callblast_audio_eigh'] = array(
    'field_name' => 'field_callblast_audio_eigh',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '14',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 8 message',
      'weight' => '14',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_file
  $fields['callblast-field_callblast_audio_file'] = array(
    'field_name' => 'field_callblast_audio_file',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Main Message',
      'weight' => '-2',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_five
  $fields['callblast-field_callblast_audio_five'] = array(
    'field_name' => 'field_callblast_audio_five',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '11',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 5 message',
      'weight' => '11',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_four
  $fields['callblast-field_callblast_audio_four'] = array(
    'field_name' => 'field_callblast_audio_four',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 4 message',
      'weight' => '10',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_nine
  $fields['callblast-field_callblast_audio_nine'] = array(
    'field_name' => 'field_callblast_audio_nine',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '15',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 9 message',
      'weight' => '15',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_one
  $fields['callblast-field_callblast_audio_one'] = array(
    'field_name' => 'field_callblast_audio_one',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '7',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 1 message',
      'weight' => '7',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_options
  $fields['callblast-field_callblast_audio_options'] = array(
    'field_name' => 'field_callblast_audio_options',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '6',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Options Message',
      'weight' => '6',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_seve
  $fields['callblast-field_callblast_audio_seve'] = array(
    'field_name' => 'field_callblast_audio_seve',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '13',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 7 message',
      'weight' => '13',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_six
  $fields['callblast-field_callblast_audio_six'] = array(
    'field_name' => 'field_callblast_audio_six',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '12',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 6 message',
      'weight' => '12',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_three
  $fields['callblast-field_callblast_audio_three'] = array(
    'field_name' => 'field_callblast_audio_three',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 3 message',
      'weight' => '9',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_two
  $fields['callblast-field_callblast_audio_two'] = array(
    'field_name' => 'field_callblast_audio_two',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_options',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'swftools_no_file',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Button 2 message',
      'weight' => '8',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_callblast_audio_url
  $fields['callblast-field_callblast_audio_url'] = array(
    'field_name' => 'field_callblast_audio_url',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_callblast_audio_url][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Main Message URL',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_callblast_call_forward
  $fields['callblast-field_callblast_call_forward'] = array(
    'field_name' => 'field_callblast_call_forward',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_callblast_call_forward][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Forward Call To',
      'weight' => 0,
      'description' => 'Enter a number for call forwarding. This is the number callers will be directed to when they press "0". (E.g. Press "0" to be connected with your state senator; press "0" to be connected with a staff person who can assist you with X; press "0" to speak with an operator.) ',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_callblast_calllist
  $fields['callblast-field_callblast_calllist'] = array(
    'field_name' => 'field_callblast_calllist',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'callblast_list',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Call List',
      'weight' => '-4',
      'description' => '',
      'type' => 'callblast_calllist',
      'module' => 'callblast',
    ),
  );

  // Exported field: field_callblast_end
  $fields['callblast-field_callblast_end'] = array(
    'field_name' => 'field_callblast_end',
    'type_name' => 'callblast',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'End Time',
      'weight' => '8',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_callblast_scheduled_start
  $fields['callblast-field_callblast_scheduled_start'] = array(
    'field_name' => 'field_callblast_scheduled_start',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '0:+1',
      'label_position' => 'above',
      'label' => 'Scheduled Start Time',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_callblast_script
  $fields['callblast-field_callblast_script'] = array(
    'field_name' => 'field_callblast_script',
    'type_name' => 'callblast',
    'display_settings' => array(
      'weight' => '12',
      'parent' => 'group_advanced',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_callblast_script][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Script',
      'weight' => '12',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_callblast_start
  $fields['callblast-field_callblast_start'] = array(
    'field_name' => 'field_callblast_start',
    'type_name' => 'callblast',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Start Time',
      'weight' => '7',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Blast sent');
  t('Button 1 message');
  t('Button 2 message');
  t('Button 3 message');
  t('Button 4 message');
  t('Button 5 message');
  t('Button 6 message');
  t('Button 7 message');
  t('Button 8 message');
  t('Button 9 message');
  t('Call List');
  t('End Time');
  t('Forward Call To');
  t('Main Message');
  t('Main Message URL');
  t('Options Message');
  t('Scheduled Start Time');
  t('Script');
  t('Start Time');

  return $fields;
}
