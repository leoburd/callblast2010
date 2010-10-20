<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function call_blast_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:callblast
  $menu_links['features:callblast'] = array(
    'menu_name' => 'features',
    'link_path' => 'callblast',
    'router_path' => 'callblast',
    'link_title' => 'Call Blasts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: features:callblast/instructions
  $menu_links['features:callblast/instructions'] = array(
    'menu_name' => 'features',
    'link_path' => 'callblast/instructions',
    'router_path' => 'callblast/instructions',
    'link_title' => 'Instructions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: features:callblast/record
  $menu_links['features:callblast/record'] = array(
    'menu_name' => 'features',
    'link_path' => 'callblast/record',
    'router_path' => 'callblast/record',
    'link_title' => 'Record Message',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: features:callblast/recordings
  $menu_links['features:callblast/recordings'] = array(
    'menu_name' => 'features',
    'link_path' => 'callblast/recordings',
    'router_path' => 'callblast/recordings',
    'link_title' => 'Review Recordings',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: features:calllists
  $menu_links['features:calllists'] = array(
    'menu_name' => 'features',
    'link_path' => 'calllists',
    'router_path' => 'calllists',
    'link_title' => 'Call Lists',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: features:callstatus
  $menu_links['features:callstatus'] = array(
    'menu_name' => 'features',
    'link_path' => 'callstatus',
    'router_path' => 'callstatus',
    'link_title' => 'Call Status',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: features:node/add/callblast
  $menu_links['features:node/add/callblast'] = array(
    'menu_name' => 'features',
    'link_path' => 'node/add/callblast',
    'router_path' => 'node/add/callblast',
    'link_title' => 'Create a Call Blast',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: features:node/add/calllist
  $menu_links['features:node/add/calllist'] = array(
    'menu_name' => 'features',
    'link_path' => 'node/add/calllist',
    'router_path' => 'node/add/calllist',
    'link_title' => 'Create Call List',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Call Blasts');
  t('Call Lists');
  t('Call Status');
  t('Create Call List');
  t('Create a Call Blast');
  t('Instructions');
  t('Record Message');
  t('Review Recordings');


  return $menu_links;
}
