<?php

/**
 * Implementation of hook_node_info().
 */
function calllist_node_info() {
  $items = array(
    'calllist' => array(
      'name' => t('Call List'),
      'module' => 'features',
      'description' => t('Create "call lists" for the Call Blast module. (Note: These are simple call lists, meant to provide an example of how call lists can be made available for use with call blasts.)'),
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
function calllist_views_api() {
  return array(
    'api' => '2',
  );
}
