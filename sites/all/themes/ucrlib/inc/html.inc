<?php
/**
 * @file
 * HTML template functions.
 */

/**
 * Implements hook_preprocess_html().
 */
function ucrlib_preprocess_html(&$vars) {
  // Add viewport.
  $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );
  drupal_add_html_head($viewport, 'viewport');

  // Force IE to use most up-to-date render engine.
  $xua = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=edge',
    ),
  );
  drupal_add_html_head($xua, 'x-ua-compatible');

  //////////////////////////////
  // HTML5 Base Theme Forwardport
  //
  // Backports the following changes made to Drupal 8:
  // - #1077566: Convert html.tpl.php to HTML5.
  //////////////////////////////
  // Initializes attributes which are specific to the html and body elements.
  $vars['html_attributes_array'] = array();
  $vars['rdf_attributes_array'] = array();
  $vars['body_attributes_array'] = array();

  // HTML element attributes.
  $vars['html_attributes_array']['lang'] = $GLOBALS['language']->language;
  $vars['html_attributes_array']['dir'] = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

  // Update RDF Namespacing
  if (module_exists('rdf')) {
    // Adds RDF namespace prefix bindings in the form of an RDFa 1.1 prefix
    // attribute inside the html element.
    $prefixes = array();
    foreach (rdf_get_namespaces() as $prefix => $uri) {
      $vars['rdf_attributes_array']['prefix'][] = $prefix . ': ' . $uri . "\n";
    }
  }

  //////////////////////////////
  // CSS & JS
  // We don't include our css/js in the theme's .info since we minimize it
  // ourselves w/ Gulp.
  //////////////////////////////
  _ucrlib_add_css($vars);
  _ucrlib_add_js($vars);

  //////////////////////////////
  // Body classes.
  //////////////////////////////
  // Add unique classes for each page and website section
  $path = explode('/', ltrim(url($_GET['q']), '/'));
  $vars['classes_array'][] = 'section-' . $path[0];
  if(isset($path[1])) {
    $vars['classes_array'][] = 'sub-section-' . $path[1];
  }
  $vars['classes_array'][] = 'page-id-' . implode('-', $path);

  // Add Page Manager classes.
  if (function_exists('page_manager_get_current_page')) {
    if ($page = page_manager_get_current_page()) {
      $vars['classes_array'][] = 'page-manager';
      $vars['classes_array'][] = 'page-manager-' . drupal_html_class($page['name']);
      if (isset($page['handler']->conf['display']->layout)) {
        $vars['classes_array'][] = 'page-manager-layout-' . drupal_html_class($page['handler']->conf['display']->layout);
      }
    }
  }

  if (function_exists('context_active_contexts') && $contexts = context_active_contexts()) {
    foreach ($contexts as $key => $context) {
      $vars['classes_array'][] = 'context-' . drupal_html_class($key);
    }

    if (array_key_exists('about_section', $contexts)) {
      $vars['inner_title'] = TRUE;
      unset($vars['outer_title']);
    }
  }

  if (function_exists('views_get_page_view') && $page = views_get_page_view()) {
    if ($page->name == 'databases') {
      drupal_add_library('system', 'ui.tooltip');
    }
  }

  if ($node = menu_get_object()) {
    $vars['theme_hook_suggestions'][] = 'html__node__' . $node->type;
  }

}

/**
 * Implements hook_process_html().
 */
function ucrlib_process_html(&$vars) {
  //////////////////////////////
  // HTML5 Base Theme Forwardport
  //
  // Backports the following changes made to Drupal 8:
  // - #1077566: Convert html.tpl.php to HTML5.
  //////////////////////////////
  // Flatten out html_attributes and body_attributes.
  $vars['html_attributes'] = drupal_attributes($vars['html_attributes_array']);
  $vars['rdf_attributes'] = drupal_attributes($vars['rdf_attributes_array']);
  $vars['body_attributes'] = drupal_attributes($vars['body_attributes_array']);
}

/**
 * Output the theme's CSS files.
 */
function _ucrlib_add_css(&$vars) {
  // Serve webfonts
  drupal_add_css('//fast.fonts.net/cssapi/8e34de10-b0cc-483f-86d5-41a16e51b11a.css', array('group' => CSS_THEME, 'type' => 'external'));
  drupal_add_css('//fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600,700,400italic,600italic', array('group' => CSS_THEME, 'type' => 'external'));


  // Modern browser options
  $css_options = array(
    'group' => CSS_THEME,
    'every_page' => TRUE,
    'weight' => 9999,
    'preprocess' => FALSE,
  );
  // IE 8 options
  $css_ie_options = array(
    'group' => CSS_THEME,
    'every_page' => TRUE,
    'weight' => 9999,
    'preprocess' => FALSE,
  );

  // Add CSS files
  $min_css = theme_get_setting('ucrlib_minified_css');
  if ($min_css) {
    // drupal_add_css(path_to_theme() . '/css/style-ie8.min.css', $css_ie_options);
    drupal_add_css(path_to_theme() . '/css/style.min.css', $css_options);
  }
  else {
    // drupal_add_css(path_to_theme() . '/css/style-ie8.css', $css_ie_options);
    drupal_add_css(path_to_theme() . '/css/style.css', $css_options);
  }
}

/**
 * Output the theme's JS files.
 */
function _ucrlib_add_js(&$vars) {
  $min_js = theme_get_setting('ucrlib_minified_js');

  $js_options = array(
    'group' => JS_THEME,
    'every_page' => TRUE,
    'weight' => 9999,
    'preprocess' => FALSE,
  );

  // Add JS files
  if ($min_js) {
    drupal_add_js(path_to_theme() . '/js/all.min.js', $js_options);
  }
  else {
    drupal_add_js(path_to_theme() . '/js/vendor.js', $js_options);
    drupal_add_js(path_to_theme() . '/js/theme.js', $js_options);
  }
}

/*
 * Transforms all http:// or https:// to //:
 */
function ucrlib_custom_process_html(&$vars)
{

	foreach (array('head', 'styles', 'scripts') as $replace) {
		if (!isset($vars[$replace])) {
			continue;
		}

		$vars[$replace] = preg_replace('/(src|href|@import )(url\(|=)(")http(s?):/', '$1$2$3', $vars[$replace]);
	}
}