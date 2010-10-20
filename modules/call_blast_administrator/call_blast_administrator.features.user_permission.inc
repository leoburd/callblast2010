<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function call_blast_administrator_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer callblast
  $permissions['administer callblast'] = array(
    'name' => 'administer callblast',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: create callblast content
  $permissions['create callblast content'] = array(
    'name' => 'create callblast content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: create calllist content
  $permissions['create calllist content'] = array(
    'name' => 'create calllist content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: delete any callblast content
  $permissions['delete any callblast content'] = array(
    'name' => 'delete any callblast content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: delete any calllist content
  $permissions['delete any calllist content'] = array(
    'name' => 'delete any calllist content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: delete own callblast content
  $permissions['delete own callblast content'] = array(
    'name' => 'delete own callblast content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: delete own calllist content
  $permissions['delete own calllist content'] = array(
    'name' => 'delete own calllist content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: edit any callblast content
  $permissions['edit any callblast content'] = array(
    'name' => 'edit any callblast content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: edit any calllist content
  $permissions['edit any calllist content'] = array(
    'name' => 'edit any calllist content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: edit own callblast content
  $permissions['edit own callblast content'] = array(
    'name' => 'edit own callblast content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: edit own calllist content
  $permissions['edit own calllist content'] = array(
    'name' => 'edit own calllist content',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: make inbound calls
  $permissions['make inbound calls'] = array(
    'name' => 'make inbound calls',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  // Exported permission: make outbound calls
  $permissions['make outbound calls'] = array(
    'name' => 'make outbound calls',
    'roles' => array(
      '0' => 'call blast administrator',
    ),
  );

  return $permissions;
}
