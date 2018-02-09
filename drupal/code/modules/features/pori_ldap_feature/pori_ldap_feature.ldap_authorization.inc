<?php
/**
 * @file
 * pori_ldap_feature.ldap_authorization.inc
 */

/**
 * Implements hook_default_ldap_authorization().
 */
function pori_ldap_feature_default_ldap_authorization() {
  $export = array();

  $consumer_type = new stdClass();
  $consumer_type->disabled = FALSE; /* Edit this to true to make a default consumer_type disabled initially */
  $consumer_type->api_version = 1;
  $consumer_type->sid = 'pori_openldap';
  $consumer_type->consumer_type = 'drupal_role';
  $consumer_type->consumer_module = 'ldap_authorization_drupal_role';
  $consumer_type->status = TRUE;
  $consumer_type->only_ldap_authenticated = TRUE;
  $consumer_type->use_first_attr_as_groupid = FALSE;
  $consumer_type->mappings = 'a:3:{i:0;a:6:{s:12:"user_entered";s:5:"admin";s:4:"from";s:15:"GG_Drupal_Admin";s:10:"normalized";s:5:"admin";s:10:"simplified";s:5:"admin";s:5:"valid";b:0;s:13:"error_message";s:93:"Role <em class="placeholder">admin</em>_name does not exist and role creation is not enabled.";}i:1;a:6:{s:12:"user_entered";s:14:"web journalist";s:4:"from";s:23:"GG_Drupal_WebJournalist";s:10:"normalized";s:14:"web journalist";s:10:"simplified";s:14:"web journalist";s:5:"valid";b:0;s:13:"error_message";s:102:"Role <em class="placeholder">web journalist</em>_name does not exist and role creation is not enabled.";}i:2;a:6:{s:12:"user_entered";s:14:"content editor";s:4:"from";s:26:"GG_Drupal_Visit_Journalist";s:10:"normalized";s:14:"content editor";s:10:"simplified";s:14:"content editor";s:5:"valid";b:0;s:13:"error_message";s:102:"Role <em class="placeholder">content editor</em>_name does not exist and role creation is not enabled.";}}';
  $consumer_type->use_filter = TRUE;
  $consumer_type->synch_to_ldap = FALSE;
  $consumer_type->synch_on_logon = TRUE;
  $consumer_type->revoke_ldap_provisioned = TRUE;
  $consumer_type->create_consumers = TRUE;
  $consumer_type->regrant_ldap_provisioned = TRUE;
  $export['drupal_role'] = $consumer_type;

  $consumer_type = new stdClass();
  $consumer_type->disabled = FALSE; /* Edit this to true to make a default consumer_type disabled initially */
  $consumer_type->api_version = 1;
  $consumer_type->sid = 'pori_openldap';
  $consumer_type->consumer_type = 'og_group';
  $consumer_type->consumer_module = 'ldap_authorization_og';
  $consumer_type->status = TRUE;
  $consumer_type->only_ldap_authenticated = TRUE;
  $consumer_type->use_first_attr_as_groupid = FALSE;
  $consumer_type->mappings = 'a:2:{i:0;a:6:{s:4:"from";s:21:"GG_Drupal_Visit_Admin";s:12:"user_entered";s:30:"node:3183:2 (raw: node:3183:2)";s:5:"valid";b:1;s:13:"error_message";s:0:"";s:10:"normalized";s:11:"node:3183:2";s:10:"simplified";s:11:"node:3183:2";}i:1;a:6:{s:4:"from";s:26:"GG_Drupal_Visit_Journalist";s:12:"user_entered";s:30:"node:3183:2 (raw: node:3183:2)";s:5:"valid";b:1;s:13:"error_message";s:0:"";s:10:"normalized";s:11:"node:3183:2";s:10:"simplified";s:11:"node:3183:2";}}';
  $consumer_type->use_filter = TRUE;
  $consumer_type->synch_to_ldap = FALSE;
  $consumer_type->synch_on_logon = TRUE;
  $consumer_type->revoke_ldap_provisioned = TRUE;
  $consumer_type->create_consumers = FALSE;
  $consumer_type->regrant_ldap_provisioned = TRUE;
  $export['og_group'] = $consumer_type;

  return $export;
}
