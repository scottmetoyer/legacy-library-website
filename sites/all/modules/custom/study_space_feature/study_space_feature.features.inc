<?php
/**
 * @file
 * study_space_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function study_space_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function study_space_feature_image_default_styles() {
  $styles = array();

  // Exported image style: study_space_node.
  $styles['study_space_node'] = array(
    'label' => 'Study space node (700x525)',
    'effects' => array(
      3 => array(
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
function study_space_feature_node_info() {
  $items = array(
    'study_space' => array(
      'name' => t('Study space'),
      'base' => 'node_content',
      'description' => t('A room/area/etc in a <em>library</em> where people can go to study.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
