<?php

/**
 * @file
 * pori_configuration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pori_configuration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer google tag manager'.
  $permissions['administer google tag manager'] = array(
    'name' => 'administer google tag manager',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'google_tag',
  );

  // Exported permission: 'flag presentation'.
  $permissions['flag presentation'] = array(
    'name' => 'flag presentation',
    'roles' => array(
      'admin' => 'admin',
      'web journalist' => 'web journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag presentation'.
  $permissions['unflag presentation'] = array(
    'name' => 'unflag presentation',
    'roles' => array(
      'admin' => 'admin',
      'web journalist' => 'web journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use bigmenu'.
  $permissions['use bigmenu'] = array(
    'name' => 'use bigmenu',
    'roles' => array(
      'admin' => 'admin',
      'content editor' => 'content editor',
      'web journalist' => 'web journalist',
    ),
    'module' => 'bigmenu',
  );

  return $permissions;
}
