<?php

/**
 * Implementation of hook_user_default_roles().
 */
function call_blast_administrator_user_default_roles() {
  $roles = array();

  // Exported role: call blast administrator
  $roles['call blast administrator'] = array(
    'name' => 'call blast administrator',
  );

  return $roles;
}
