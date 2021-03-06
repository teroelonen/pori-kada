<?php

/**
 * @file
 * pori_attraction_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pori_attraction_feature_taxonomy_default_vocabularies() {
  return array(
    'attraction_category' => array(
      'name' => 'Attraction category',
      'machine_name' => 'attraction_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'base_i18n_mode' => 1,
      'base_language' => 'und',
    ),
    'bus_lines' => array(
      'name' => 'Bus lines',
      'machine_name' => 'bus_lines',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'base_i18n_mode' => 0,
      'base_language' => 'und',
    ),
  );
}
