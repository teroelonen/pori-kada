<?php

/**
 * @file
 * pori_configuration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pori_configuration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_admin_cancelbutton';
  $strongarm->value = 1;
  $export['content_lock_admin_cancelbutton'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_admin_verbose';
  $strongarm->value = 1;
  $export['content_lock_admin_verbose'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_allowed_formats';
  $strongarm->value = array(
    'wysiwyg' => 0,
    'full_html' => 0,
    'plain_text' => 0,
    'ds_code' => 0,
  );
  $export['content_lock_allowed_formats'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_allowed_node_types';
  $strongarm->value = array(
    'section' => 0,
    'blog' => 0,
    'blog_post' => 0,
    'webform' => 0,
    'event' => 0,
    'landing_page' => 0,
    'liftup' => 0,
    'news_item' => 0,
    'page' => 0,
    'place' => 0,
    'service' => 0,
    'service_offer' => 0,
    'feed_import_facebook' => 0,
    'feed_import_instagram' => 0,
    'feed_import_twitter' => 0,
    'feed_import_youtube_channel' => 0,
    'social_media_update' => 0,
    'attraction_card' => 0,
    'person' => 0,
    'position_of_trust' => 0,
  );
  $export['content_lock_allowed_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_unload_js';
  $strongarm->value = 1;
  $export['content_lock_unload_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_unload_js_message';
  $strongarm->value = 'If you proceed, ALL of your changes will be lost.';
  $export['content_lock_unload_js_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_lock_unload_js_message_enable';
  $strongarm->value = 1;
  $export['content_lock_unload_js_message_enable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'datalayer_add_page_meta';
  $strongarm->value = 1;
  $export['datalayer_add_page_meta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'datalayer_global_entity_meta';
  $strongarm->value = array(
    'created' => 'created',
    'language' => 'language',
    'name' => 0,
    'status' => 'status',
    'tnid' => 'tnid',
    'uid' => 'uid',
    'vid' => 'vid',
  );
  $export['datalayer_global_entity_meta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'datalayer_lib_helper';
  $strongarm->value = 0;
  $export['datalayer_lib_helper'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'datalayer_output_terms';
  $strongarm->value = 1;
  $export['datalayer_output_terms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'datalayer_vocabs';
  $strongarm->value = array(
    'accessibility' => 0,
    'allotment' => 0,
    'attraction_category' => 0,
    'berth' => 0,
    'boating' => 0,
    'bus_lines' => 0,
    'businesspori_theme' => 0,
    'city_bikes' => 0,
    'cyckling' => 0,
    'district' => 0,
    'event_types' => 0,
    'guest_pier' => 0,
    'keywords' => 0,
    'municipality' => 0,
    'office' => 0,
    'playground' => 0,
    'political_party' => 0,
    'rug_washing' => 0,
    'scald_authors' => 0,
    'scald_tags' => 0,
    'service_classification' => 0,
    'skills' => 0,
    'target_audience' => 0,
    'theme' => 0,
    'trust_unit' => 0,
    'trustee_role' => 0,
    'visitpori_theme' => 0,
    'waste' => 0,
    'waste_type' => 0,
  );
  $export['datalayer_vocabs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hotjar_settings';
  $strongarm->value = array(
    'hotjar_account' => '673332',
    'hotjar_visibility_pages' => '0',
    'hotjar_pages' => 'admin
admin/*
batch
node/add*
node/*/*
user/*/*',
    'hotjar_visibility_roles' => '0',
    'hotjar_roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      8 => 0,
      3 => 0,
      7 => 0,
      5 => 0,
      6 => 0,
    ),
  );
  $export['hotjar_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_jpeg_quality';
  $strongarm->value = '95';
  $export['image_jpeg_quality'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_item_de_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_item_de_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_page_de_pattern';
  $strongarm->value = '';
  $export['pathauto_node_page_de_pattern'] = $strongarm;

  return $export;
}
