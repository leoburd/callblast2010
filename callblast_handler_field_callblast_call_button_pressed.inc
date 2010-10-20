<?php
// $Id$
/**
 * Field handler to present callblast title 
 * related to the displayed voipcall node.
 */
class callblast_handler_field_callblast_call_button_pressed extends views_handler_field {
  function render($values) {
    $voipcall_nid = $values->callblast_call_voipcall_nid;
    $inputs = callblast_get_input($voipcall_nid); 
    $i = 0;
    $pressed = '';
    foreach ($inputs as $input) {
      $pressed .= ($i == 0) ? $input : ", $input";      
      $i++;
    }
    return $pressed;
  }
}
