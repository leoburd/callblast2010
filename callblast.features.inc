<?php

/**
 * Implementation of hook_node_info().
 */
function callblast_node_info() {
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
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function callblast_views_api() {
  return array(
    'api' => '2',
  );
}
