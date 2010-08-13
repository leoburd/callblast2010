<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _callblast_node_info() {
  $items = array(
    'callblast' => array(
      'name' => t('Call Blast'),
      'module' => 'features',
      'description' => t('Schedule a call blast. Each call blast node includes a list of numbers to receive calls. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'callblast_message' => array(
      'name' => t('Call Blast Message'),
      'module' => 'features',
      'description' => t('Voice message to blast out with call blasts'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Script (read for recording)'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
