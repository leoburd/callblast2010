<?php 
/**
 * Implementation of hook_views_data().
 * 
 * Expose callblast_call table to views, so voipcall
 * nodes can be filtered in Views based on the callblast that 
 * created them.
 */
function callblast_views_data() {
  $data = array();

  // callblast_call table
  $data['callblast_call']['table']['group'] = t('Node');

  // link callblast_call table to node table, join on callblast_nid
  $data['callblast_call']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'callblast_nid',
  );

  // link callblast_call table to node table, join on voipcall_nid
  $data['callblast_call']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'voipcall_nid',
  );

  // callblast_call.callblast_nid field
  $data['callblast_call']['callblast_nid'] = array( 
    'group' => t('Call Blast'),
    'title' => t('Call Blast Nid'),
    'help' => t('The node ID of the Call Blast node.'),
    'argument' => array(
      // todo? 'handler' => '',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Call Blast Name field
  $data['callblast_call']['callblast_title'] = array( 
    'group' => t('Call Blast'),
    'help' => t('The human readable title/name of the Call Blast node '
               .'related to the voipcall node being displayed.'),
    'field' => array(
      'title' => 'Call Blast Title',
      'field' => 'callblast_nid', // the real field
      'handler' => 'callblast_handler_field_callblast_call_callblast_title',
      'click sortable' => TRUE,
    ),
  );

  // voipcall button pressed / option selected 
  // by callee on the dial pad of the phone.  
  $data['callblast_call']['button_pressed'] = array( 
    'group' => t('Call Blast'),
    'help' => t('Display the button pressed by the call recipient. '),
    'field' => array(
      'title' => t('Button Pressed'),
      'field' => 'voipcall_nid', // real field
      'handler' => 'callblast_handler_field_callblast_call_button_pressed',
      'click sortable' => TRUE,
    ),
  );


  // callblast_call.voipcall_nid field
  $data['callblast_call']['voipcall_nid'] = array(
    'group' => t('Call Blast'),
    'title' => t('Voip Call Nid'),
    'help' => t('The node ID of the Voip Call node.'),
    'argument' => array(
      // todo? 'handler' => '',
      'name field' => 'title', // the field to display in the summary.
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function callblast_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'callblast'),
    ),
    'handlers' => array(
      'callblast_handler_field_callblast_call_callblast_title' => array(
        'parent' => 'views_handler_field',
      ),
      'callblast_handler_field_callblast_call_button_pressed' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
 
