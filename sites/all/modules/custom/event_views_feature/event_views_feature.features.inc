<?php
/**
 * @file
 * event_views_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function event_views_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function event_views_feature_image_default_styles() {
  $styles = array();

  // Exported image style: event_list_thumb.
  $styles['event_list_thumb'] = array(
    'label' => 'Event list thumb (110x110)',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 110,
          'height' => 110,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
