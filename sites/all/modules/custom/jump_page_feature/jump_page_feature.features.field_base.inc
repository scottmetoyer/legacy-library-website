<?php
/**
 * @file
 * jump_page_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function jump_page_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_jump_item'
  $field_bases['field_jump_item'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_jump_item',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  return $field_bases;
}
