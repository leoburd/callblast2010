<?php

/**
 * Implementation of hook_content_default_fields().
 */
function calllist_content_default_fields() {
  $fields = array();

  // Exported field: field_calllist_phone_num_csv
  $fields['calllist-field_calllist_phone_num_csv'] = array(
    'field_name' => 'field_calllist_phone_num_csv',
    'type_name' => 'calllist',
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
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'txt csv',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Upload Phone Numbers',
      'weight' => '-3',
      'description' => '<p>Upload a list of phone numbers. The list should be formatted like this:</p>
<p>
555 555 5555<br/>
666 666 6666<br/>
777 777 7777<br/>
</p>
<p>or like this:</p>
<p>
555 555 5555, Leo Burd<br/>
666 666 6666, Bryan Hirsch<br/>
777 777 7777, George Washington<br/>
</p>',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_calllist_phone_numbers
  $fields['calllist-field_calllist_phone_numbers'] = array(
    'field_name' => 'field_calllist_phone_numbers',
    'type_name' => 'calllist',
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '70',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_calllist_phone_numbers][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Phone numbers',
      'weight' => '-4',
      'description' => 'To include names, please format numbers like this: 
555 555 5555, Leo Burd<br/>
666 666 6666, Bryan Hirsch<br/>',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Phone numbers');
  t('Upload Phone Numbers');

  return $fields;
}
