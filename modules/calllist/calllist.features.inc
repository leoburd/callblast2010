<?php

/**
 * Implementation of hook_content_default_fields().
 */
function calllist_content_default_fields() {
  module_load_include('inc', 'calllist', 'calllist.defaults');
  $args = func_get_args();
  return call_user_func_array('_calllist_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function calllist_node_info() {
  module_load_include('inc', 'calllist', 'calllist.features.node');
  $args = func_get_args();
  return call_user_func_array('_calllist_node_info', $args);
}
