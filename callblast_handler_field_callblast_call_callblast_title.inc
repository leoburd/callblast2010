<?php
// $Id$
/**
 * Field handler to present callblast title 
 * related to the displayed voipcall node.
 */
class callblast_handler_field_callblast_call_callblast_title extends views_handler_field {
  function render($values) {
    $callblast_nid = $values->callblast_call_callblast_nid;
    $result = db_query("SELECT title FROM {node} WHERE nid = %d", $callblast_nid);
    $title = db_result($result);
    $title = check_markup($title);

    return $title; 
  }
}
