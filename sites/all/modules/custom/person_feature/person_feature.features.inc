<?php
/**
 * @file
 * person_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function person_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function person_feature_image_default_styles() {
  $styles = array();

  // Exported image style: person_node.
  $styles['person_node'] = array(
    'label' => 'Person node (700x700)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 700,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: person_thumb.
  $styles['person_thumb'] = array(
    'label' => 'Person thumb (100x100)',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
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
function person_feature_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('A person.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
