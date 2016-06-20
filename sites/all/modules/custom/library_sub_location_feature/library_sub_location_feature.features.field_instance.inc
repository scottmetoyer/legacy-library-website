<?php
/**
 * @file
 * library_sub_location_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function library_sub_location_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-library_sub_location-field_library'
  $field_instances['node-library_sub_location-field_library'] = array(
    'bundle' => 'library_sub_location',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The library this sub-location is in.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser2' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser3' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_library',
    'label' => 'Library',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'content_taxonomy_opt_groups' => FALSE,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Library');
  t('The library this sub-location is in.');

  return $field_instances;
}
