<?php
/**
 * @file
 * exhibit_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function exhibit_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function exhibit_feature_node_info() {
  $items = array(
    'exhibit' => array(
      'name' => t('Exhibit'),
      'base' => 'node_content',
      'description' => t('An exhibit.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
