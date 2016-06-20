<?php
/**
 * @file
 * Field template functions.
 */

/**
 * Implements hook_preprocess_field().
 */
function ucrlib_preprocess_field(&$vars) {
  // Set shortcut variables. Hooray for less typing!
  $field = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $item_classes = array();

  $base_class = $field;

  // Field (outer) wrapper.
  $vars['use_field_wrapper'] = FALSE;
  $use_field_wrapper = &$vars['use_field_wrapper'];
  $vars['field_wrapper_element'] = 'div';
  $field_wrapper_element = &$vars['field_wrapper_element'];

  // Items wrapper.
  $vars['use_items_wrapper'] = FALSE;
  $use_items_wrapper = &$vars['use_items_wrapper'];
  $vars['items_wrapper_element'] = 'div';
  $items_wrapper_element = &$vars['items_wrapper_element'];

  // Individual item wrapper.
  $vars['use_item_wrapper'] = TRUE;
  $use_item_wrapper = &$vars['use_item_wrapper'];
  $vars['item_wrapper_element'] = 'div';
  $item_wrapper_element = &$vars['item_wrapper_element'];

  // Label wrapper.
  $vars['label_wrapper_element'] = 'div';
  $label_wrapper_element = &$vars['label_wrapper_element'];

  // print '<strong>Field:</strong> ' . $field . '<br/>';
  // print '<strong>Bundle:</strong> ' . $bundle  . '<br/>';
  // print '<strong>Mode:</strong> ' . $mode .'<br/>';
  // dpm($vars);

  switch ($field) {
    // Example usage of theme_hook_suggestions:
    // case 'field_tags':
    //   $vars['theme_hook_suggestions'][] = 'field__custom_separated';
    //   break;
  }

  $base_class = drupal_html_class($base_class);
  // Remove "field-" from $base_class
  if (strpos($base_class, 'field-') === 0) {
    $base_class = substr($base_class, 6);
  }

  // Set field classes.
  $classes = array($base_class);
  $title_classes[] = $base_class . '-label';
  $title_classes[] = drupal_html_class($bundle) . '__' . $base_class . '-label';
  $content_classes[] = $base_class . '-items';
  $item_classes[] = $base_class . '-item';
  $item_classes[] = drupal_html_class($bundle) . '__' . $base_class;
  $item_classes[] = drupal_html_class($bundle) . '--' . drupal_html_class($mode) . '__' . $base_class;

  // Apply odd or even classes along with our custom classes to each item
  foreach ($vars['items'] as $delta => $item) {
    $item_classes[] = $delta % 2 ? 'odd' : 'even';
    $vars['item_attributes_array'][$delta]['class'] = $item_classes;
  }

  // Add line breaks to plain text textareas.
  if ($vars['element']['#field_type'] == 'text_long' && $vars['element']['#items'][0]['format'] == NULL) {
    $vars['items'][0]['#markup'] = nl2br($vars['items'][0]['#markup']);
  }
}

/**
 * Helper function to render content.
 */
function _ucrlib_field_render_content($item, $field, $bundle, $view_mode) {
  if ($field == 'body' && $view_mode == 'teaser') {
    $content = text_summary($item['#markup'], 'plain_text', 180);
  }
  else {
    $content = drupal_render($item);
  }

  return $content;
}

/**
 * Overrides theme_field().
 * Remove the hard coded classes so we can add them in preprocess functions.
 */
function ucrlib_field($vars) {
  // Set shortcut variables. Hooray for less typing!
  $field = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];

  $output = '';

  // Render the label, if it's not hidden.
  if (!$vars['label_hidden']) {
    $output .= '<div ' . $vars['title_attributes'] . '>' . $vars['label'] . '</div>';
  }

  // Render the items.
  if ($vars['use_items_wrapper']) {
    $output .= '<'. $vars['items_wrapper_element'] . ' ' . $vars['content_attributes'] . '>';
  }
  foreach ($vars['items'] as $delta => $item) {
    // Render the individual item.
    if ($vars['use_item_wrapper']) {
      $output .= '<' . $vars['item_wrapper_element'] . ' ' . $vars['item_attributes'][$delta] . '>';
    }
    $output .= _ucrlib_field_render_content($item, $field, $bundle, $mode);
    if ($vars['use_item_wrapper']) {
      $output .= '</' . $vars['item_wrapper_element'] . '>';
    }
  }
  if ($vars['use_items_wrapper']) {
    $output .= '</' . $vars['items_wrapper_element'] . '>';
  }

  // Render the top-level DIV.
  if ($vars['use_field_wrapper']) {
    $output = '<' . $vars['item_wrapper_element'] . ' class="' . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . '</' . $vars['item_wrapper_element'] . '>';
  }

  return $output;
}
