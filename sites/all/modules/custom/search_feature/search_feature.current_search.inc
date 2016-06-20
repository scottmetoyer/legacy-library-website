<?php
/**
 * @file
 * search_feature.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function search_feature_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'default_node_index_block';
  $item->label = 'Default node index block';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Found <strong>[facetapi_results:result-count]</strong> results containing the words: <strong>[facetapi_results:keys]</strong>',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'h1',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '0',
    ),
  );
  $export['default_node_index_block'] = $item;

  return $export;
}
