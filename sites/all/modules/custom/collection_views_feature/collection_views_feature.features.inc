<?php
/**
 * @file
 * collection_views_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function collection_views_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function collection_views_feature_image_default_styles() {
  $styles = array();

  // Exported image style: collection_list_thumb.
  $styles['collection_list_thumb'] = array(
    'label' => 'Collection list thumb (100x100)',
    'effects' => array(
      8 => array(
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
