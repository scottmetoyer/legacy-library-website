<?php
/**
 * @file
 * conference_room_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function conference_room_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function conference_room_feature_image_default_styles() {
  $styles = array();

  // Exported image style: conference_room_node.
  $styles['conference_room_node'] = array(
    'label' => 'Conference room node (700x525)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 525,
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
function conference_room_feature_node_info() {
  $items = array(
    'conference_room' => array(
      'name' => t('Conference room'),
      'base' => 'node_content',
      'description' => t('A room for having conferences.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
