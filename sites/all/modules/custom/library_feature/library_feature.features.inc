<?php
/**
 * @file
 * library_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function library_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function library_feature_image_default_styles() {
  $styles = array();

  // Exported image style: library_node.
  $styles['library_node'] = array(
    'label' => 'Library node (800x452)',
    'effects' => array(
      17 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 452,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function library_feature_node_info() {
  $items = array(
    'library' => array(
      'name' => t('Library'),
      'base' => 'node_content',
      'description' => t('A physical, brick-and-mortar library facility.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
