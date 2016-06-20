<?php
/**
 * @file
 * minimal_page_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function minimal_page_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function minimal_page_feature_node_info() {
  $items = array(
    'minimal_page' => array(
      'name' => t('Minimal page'),
      'base' => 'node_content',
      'description' => t('A very slimmed down version of a <em>basic page</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
