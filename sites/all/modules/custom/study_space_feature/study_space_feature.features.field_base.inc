<?php
/**
 * @file
 * study_space_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function study_space_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_study_space_features'
  $field_bases['field_study_space_features'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_study_space_features',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'study_space_features',
          'parent' => 0,
        ),
      ),
      'options_list_callback' => 'content_taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
