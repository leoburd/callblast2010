<?php
/**
 * @file callbblast.record.inc
 *  callback for callblast/record
 */
/**
 * @return $form
 *  array, see Form API
 */
function callblast_record_form() {
  $form['callblast'] = array(
    '#type' => 'textfield', 
    '#title' => t('Subject'), 
    '#default_value' => $node->title, 
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => TRUE,
  );  

  return $form; 
}
