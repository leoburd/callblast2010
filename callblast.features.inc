<?php

/**
 * Implementation of hook_content_default_fields().
 */
function callblast_content_default_fields() {
  module_load_include('inc', 'callblast', 'callblast.defaults');
  $args = func_get_args();
  return call_user_func_array('_callblast_content_default_fields', $args);
}

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function callblast_fieldgroup_default_groups() {
  module_load_include('inc', 'callblast', 'callblast.defaults');
  $args = func_get_args();
  return call_user_func_array('_callblast_fieldgroup_default_groups', $args);
}

/**
 * Implementation of hook_node_info().
 */
function callblast_node_info() {
  module_load_include('inc', 'callblast', 'callblast.features.node');
  $args = func_get_args();
  return call_user_func_array('_callblast_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function callblast_views_default_views() {
  module_load_include('inc', 'callblast', 'callblast.features.views');
  $args = func_get_args();
  return call_user_func_array('_callblast_views_default_views', $args);
}
