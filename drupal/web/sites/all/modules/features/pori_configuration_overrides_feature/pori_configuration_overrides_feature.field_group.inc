<?php
/**
 * @file
 * pori_configuration_overrides_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pori_configuration_overrides_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audiance|node|landing_page|form';
  $field_group->group_name = 'group_audiance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Groups audiance',
    'weight' => '3',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-audiance field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_audiance|node|landing_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Groups audiance');

  return $field_groups;
}
