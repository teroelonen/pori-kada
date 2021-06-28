<?php

/**
 * Implements hook_preprocess_html().
 */

function kada_preprocess_html(&$variables) {
  global $language;
  $domain = domain_get_domain();
  $group = og_context();

  switch ($domain['machine_name']) {
    case 'businesspori_fi':
      $variables['cookiebot_head'] = '<script id="Cookiebot" src="https://consent.cookiebot.com/uc.js" data-cbid="a64f5e13-0c70-4d9d-bd65-64adff59bc3d" type="text/javascript" data-blockingmode="auto"></script>';
      $variables['cookiebot_footer'] = '<script id="CookieDeclaration" src="https://consent.cookiebot.com/a64f5e13-0c70-4d9d-bd65-64adff59bc3d/cd.js" type="text/javascript" async></script>';
      break;
    case 'pori_fi':
      $variables['cookiebot_head'] = '<script id="Cookiebot" src="https://consent.cookiebot.com/uc.js" data-cbid="90764a52-430d-45db-ae4c-3202141c8d0a" type="text/javascript" data-blockingmode="auto"></script>';
      $variables['cookiebot_footer'] = '<script id="CookieDeclaration" src="https://consent.cookiebot.com/90764a52-430d-45db-ae4c-3202141c8d0a/cd.js" type="text/javascript" async></script>';
      break;
    case 'visitpori_fi':
      $variables['cookiebot_head'] = '<script id="Cookiebot" src="https://consent.cookiebot.com/uc.js" data-cbid="f0019430-0fe6-40ca-825b-5f85616538d3" type="text/javascript" data-blockingmode="auto"></script>';
      $variables['cookiebot_footer'] = '<script id="CookieDeclaration" src="https://consent.cookiebot.com/f0019430-0fe6-40ca-825b-5f85616538d3/cd.js" type="text/javascript" async></script>';
      break;
    default:
    $variables['cookiebot_head'] = $variables['cookiebot_footer'] = '';
      break;
  }

  $path = current_path();

  drupal_add_js(drupal_get_path('theme', variable_get('theme_default', NULL)) . '/dist/js/vendor/modernizr.min.js', array(
    'scope' => 'header',
    'weight' => '15'
  ));

  drupal_add_js(drupal_get_path('theme', variable_get('theme_default', NULL)) . '/dist/js/vendor/masonry.pkgd.min.js', array(
    'scope' => 'footer',
    'weight' => '15'
  ));

  drupal_add_js(drupal_get_path('theme', variable_get('theme_default', NULL)) . '/dist/js/vendor/imagesloaded.pkgd.min.js', array(
    'scope' => 'header',
    'weight' => '15'
  ));

  // TODO moment should be conditionally loaded
  drupal_add_js(drupal_get_path('theme', variable_get('theme_default', NULL)) . '/dist/js/vendor/moment.min.js', array(
    'scope' => 'footer',
    'weight' => '15'
  ));

  // Add chat to event add form page.
  if ($path == 'event/add' && $language->language == 'fi') {
    drupal_add_js(drupal_get_path('theme', variable_get('theme_default', NULL)) . '/dist/js/vendor/event.js', array(
      'scope' => 'header',
      'weight' => '15',
    ));
  }

  // Fetch body classes from custom static variable.
  // @see kada_page_feature_views_post_execute()
  $classes = &drupal_static('kada_page_classes');

  if ($classes) {
    $variables['classes_array'][] = $classes;
  }

  $node = menu_get_object();

  if (!empty($node->field_theme_main_page) && $node->field_theme_main_page['und'][0]['value'] == 1) {
    $variables['classes_array'][] = 'theme-main-page';
  }
}
