<?php
/**
 * @file callblast.admin.inc
 *  Form for admin/settings/callblast page.
 */
/**
 * Callblack for admin/settings/callblast page.
 * 
 *  @ingroup forms
 *  @see system_settings_form().
 */
function callblast_admin_settings() {
  $form['callblast_queue_size'] = array(
    '#title' => t('Queue Size'),
    '#type' => 'textfield',
    '#size' => 6,
    '#default_value' => variable_get('callblast_queue_size', 10),
    '#description' => t('This setting determines how many calls get sent at a time in any given callblast.'), 
  );

  return system_settings_form($form);
}
