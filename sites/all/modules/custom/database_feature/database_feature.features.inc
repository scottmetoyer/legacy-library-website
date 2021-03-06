<?php
/**
 * @file
 * database_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function database_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function database_feature_node_info() {
  $items = array(
    'database' => array(
      'name' => t('Database'),
      'base' => 'node_content',
      'description' => t('A link to an informational database.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}