<?php
/**
 * @file
 * common_field_bases_feature.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function common_field_bases_feature_image_default_styles() {
  $styles = array();

  // Exported image style: carousel_item.
  $styles['carousel_item'] = array(
    'label' => 'Carousel item (1200x675)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 675,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: paragraphs_image_left_right.
  $styles['paragraphs_image_left_right'] = array(
    'label' => 'Paragraphs image left/right (700x525)',
    'effects' => array(
      19 => array(
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
 * Implements hook_paragraphs_info().
 */
function common_field_bases_feature_paragraphs_info() {
  $items = array(
    'basic_text' => array(
      'name' => 'Basic text',
      'bundle' => 'basic_text',
      'locked' => '1',
    ),
    'two_column_image_left' => array(
      'name' => 'Two column, image left',
      'bundle' => 'two_column_image_left',
      'locked' => '1',
    ),
    'two_column_image_right' => array(
      'name' => 'Two column, image right',
      'bundle' => 'two_column_image_right',
      'locked' => '1',
    ),
  );
  return $items;
}
