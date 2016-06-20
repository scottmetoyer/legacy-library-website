<?php
/**
 * @file
 * Field Collection template functions.
 */

/**
 * Implements hook_preprocess_field_collection_item().
 */
function ucrlib_preprocess_field_collection_item(&$vars) {
  if ($vars['elements']['#bundle'] == 'field_jump_item') {
    $vars['tpl_content']['link'] = l(decode_entities($vars['field_link'][0]['title']), $vars['field_link'][0]['url']);
    $vars['tpl_content']['icon'] = $vars['field_icon'][0]['value'];
    $vars['tpl_content']['description'] = $vars['field_short_description'][0]['value'];
  }
}
