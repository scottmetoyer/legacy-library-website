<?php
/**
 * @file
 * Node template functions.
 */

require_once dirname(__FILE__) . '/node-fields.inc';


/**
 * Implements hook_preprocess_node().
 */
function ucrlib_preprocess_node(&$vars, $hook) {
  // Set shortcut variables. Hooray for less typing!
  $type = $vars['type'];
  $mode = $vars['view_mode'];
  $node = $vars['node'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  // Add article ARIA role.
  $vars['attributes_array']['role'] = 'article';

  // Template suggestions
  $vars['theme_hook_suggestions'][] = 'node__' . $type . '__' . $mode;

  $classes[] = drupal_html_class($type) . '--' . drupal_html_class($mode);
  $classes[] = 'view-mode-' . drupal_html_class($mode);

  // dpm(theme_get_suggestions(arg(), 'node'));
  // dpm($vars);
  // dpm($vars['node']);

  // Node-type-specific preprocess functions, like
  // ucrlib_preprocess_node__page() or ucrlib_preprocess_node__story().
  $function = __FUNCTION__ . '__' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars, $hook);
  }
}

/**
 * Implements hook_preprocess_node() for "collection".
 */
function ucrlib_preprocess_node__collection(&$vars, $hook) {
  // Libraries
  _ucrlib_libraries($vars, $vars['node']);
  $vars['libraries'] = implode(', ', $vars['libraries']);

  // Access this collection
  _ucrlib_sidebar_cta($vars, $vars['node']);

  // Access this collection
  _ucrlib_sidebar_cta($vars, $vars['node']);

  // Contact person
  _ucrlib_person($vars, $vars['node']);
//
  // Contact Deparment
  _ucrlib_department($vars, $vars['node']);

  // Subject areas
  _ucrlib_subject_areas($vars, $vars['node']);

  // Related resources
  _ucrlib_links($vars, $vars['node']);

  // Related collections
  _ucrlib_collections($vars, $vars['node']);

  // Related guides
  _ucrlib_guides($vars, $vars['node']);
}

/**
 * Implements hook_preprocess_node() for "conference room".
 */
function ucrlib_preprocess_node__conference_room(&$vars, $hook) {
  // Description
  _ucrlib_short_description($vars, $vars['node']);

  // Link
  _ucrlib_link($vars, $vars['node']);

  // Capacity
  _ucrlib_capacities($vars, $vars['node']);

  // Hours
  _ucrlib_hours($vars, $vars['node']);

  // Equipment
  _ucrlib_equipment($vars, $vars['node']);

  // Cost
  _ucrlib_text_list($vars, $vars['node'], 'cost');
}

/**
 * Implements hook_preprocess_node() for "database".
 */
function ucrlib_preprocess_node__database(&$vars, $hook) {
  // dpm($vars);

  // Link
  _ucrlib_link($vars, $vars['node']);

  // Very short description
  _ucrlib_very_short_description($vars, $vars['node']);

  // Is a trial database?
  _ucrlib_trial($vars, $vars['node']);
	  // Trial end date
  _ucrlib_trial_end_date($vars, $vars['node']);

  // Require user to be logged in or Open Access
  _ucrlib_type_of_access($vars, $vars['node']);
}

/**
 * Implements hook_preprocess_node() for "department".
 */
function ucrlib_preprocess_node__department(&$vars, $hook) {
  // dpm($vars);

  // Phone
  _ucrlib_phone($vars, $vars['node']);

  // FAX
  _ucrlib_fax($vars, $vars['node']);

  // Email link
  $vars['email'] = l(
    t('Email'),
    'eform/submit/department-contact-form',
    array(
      'query' => array(
        'field_department' => $vars['nid'],
      ),
      'attributes' => array(
        'class' => 'email-link',
      ),
    )
  );

  // Description
  _ucrlib_short_description($vars, $vars['node']);

  // Related resources
  _ucrlib_links($vars, $vars['node']);

  // Staff
  $vars['staff'] = views_embed_view('staff', 'block_1');

  // Hours
  _ucrlib_department_hours($vars, $vars['node']);
}

/**
 * Implements hook_preprocess_node() for "event".
 */
function ucrlib_preprocess_node__event(&$vars, $hook) {

  // Dates, RSVP links, Library, Room
  _ucrlib_event_date_links($vars, $vars['node']);

  // Default images
  _ucrlib_default_images($vars, $vars['node']);

  if (isset($vars['date_links']['links'][0]['library_name']) && isset($vars['date_links']['links'][0]['room'])) {
    $vars['location'] = $vars['date_links']['links'][0]['library_name'] . ', ' . $vars['date_links']['links'][0]['room'];
  }


  // Some fields are only needed on a full node
  if ($vars['view_mode'] == 'full')
  {
  	$vars['library_name'] = $vars['date_links']['links'][0]['library_name'];
  	$vars['library_room'] = $vars['date_links']['links'][0]['room'];

    // Share buttons
    _ucrlib_share($vars, $vars['node']);

    // Instructors
    _ucrlib_people($vars, $vars['node']);
    $vars['instructors'] = $vars['people'];
    unset($vars['people']);

    // Related information
    _ucrlib_links($vars, $vars['node']);

    // RSVP help text
    _ucrlib_very_short_description($vars, $vars['node']);
    $vars['event_rsvp_text'] = $vars['description'];
    unset($vars['description']);

    // Contact person
    _ucrlib_person($vars, $vars['node']);

    // Parking
     _ucrlib_parking($vars, $vars['node']);

  }
  else if($vars['view_mode'] == 'teaser')
  {
  	//This displays the event type example Workshop Instruction Sesstion ....
  	if (isset($vars['date_links']['links'][0]['event_type']) ) {
  		$vars['event_type'] = $vars['date_links']['links'][0]['event_type'];
  	}
  	//This sets the color of the background
  	if (isset($vars['date_links']['links'][0]['color']) ) {
  		$vars['color'] = $vars['date_links']['links'][0]['color'];
  	}
  }
//   dpm($vars);
}

/**
 * Implements hook_preprocess_node() for "exhibit".
 */
function ucrlib_preprocess_node__exhibit(&$vars, $hook) {
  // Carousel
  _ucrlib_carousel($vars, $vars['node']);

  // Related information
  _ucrlib_links($vars, $vars['node']);
}

/**
 * Implements hook_preprocess_node() for "library".
 */
function ucrlib_preprocess_node__library(&$vars, $hook) {
	// email
  _ucrlib_email_library($vars, $vars['node']);

  	// Phone
  _ucrlib_phone($vars, $vars['node']);

  // Subjects
  _ucrlib_subject_areas($vars, $vars['node']);

  // Map
  _ucrlib_map($vars, $vars['node']);

  // Google directions
  _ucrlib_google_directions($vars, $vars['node']);

  // Public transit
  _ucrlib_public_transit($vars, $vars['node']);

  // Parking
  _ucrlib_parking($vars, $vars['node']);

  // ADA info
  _ucrlib_ada_info($vars, $vars['node']);

  // Address 1
  _ucrlib_address1($vars, $vars['node']);

  // Address 2
  _ucrlib_address2($vars, $vars['node']);

  // Hours
  $block = module_invoke('ucrlib_custom', 'block_view', 'library');
  $vars['hours'] = render($block);
}

/**
 * Implements hook_preprocess_node() for "map".
 */
function ucrlib_preprocess_node__map(&$vars, $hook) {
  $vars['latitude'] = $vars['content']['field_map_latitude'][0]['#markup'];
  $vars['longitude'] = $vars['content']['field_map_longitude'][0]['#markup'];
  $vars['zoom'] = $vars['content']['field_map_zoom'][0]['#markup'];
}

/**
 * Implements hook_preprocess_node() for "news".
 */
function ucrlib_preprocess_node__news(&$vars, $hook) {
  // Date
  _ucrlib_date($vars, $vars['node']);

  // Contact
  _ucrlib_person($vars, $vars['node']);

  // Related information
  _ucrlib_links($vars, $vars['node']);

  // Default images
  _ucrlib_default_images($vars, $vars['node']);

  // Read more
  $vars['read_more'] = l(t('Read full story'), 'node/'. $vars['node']->nid);

  // Some fields are only needed on a full node
  if ($vars['view_mode'] == 'full') {
    // Share buttons
    _ucrlib_share($vars, $vars['node']);
  }
}

/**
 * Implements hook_preprocess_node() for "page".
 */
function ucrlib_preprocess_node__page(&$vars, $hook) {
  // Right sidebar cta?
  _ucrlib_sidebar_cta($vars, $vars['node']);

  // Related information
  _ucrlib_links($vars, $vars['node']);

  // Carousel
  _ucrlib_carousel($vars, $vars['node']);
}

/**
 * Implements hook_preprocess_node() for "person".
 */
function ucrlib_preprocess_node__person(&$vars, $hook) {

  // Email
  _ucrlib_email($vars, $vars['node']);

  // Phone
  _ucrlib_phone($vars, $vars['node']);

  // Subject areas
  _ucrlib_subject_areas($vars, $vars['node']);

  // Subject specialties
  _ucrlib_subject_specialties($vars, $vars['node']);

  // Job title
  _ucrlib_job_title($vars, $vars['node']);
//Departments
  _ucrlib_departments($vars, $vars['node']);

  // Default images
  _ucrlib_default_images($vars, $vars['node']);

  // Contact form link
  _ucrlib_link($vars, $vars['node']);
}

/**
 * Implements hook_preprocess_node() for "study space".
 */
function ucrlib_preprocess_node__study_space(&$vars, $hook) {
  // Library
  _ucrlib_library($vars, $vars['node']);

  // Link to all study spaces
  $vars['all_study_spaces_link'] = l(
    t('See all study spaces in @library_name', array('@library_name' => $vars['library_name'])),
    'using-the-library/study-spaces',
    array('query' =>
      array(
        'l[]' => $vars['library_id'],
      ),
    )
  );

  // Link
  _ucrlib_link($vars, $vars['node']);

  // Library floor
  _ucrlib_floor($vars, $vars['node']);

  // Features/type
  _ucrlib_features($vars, $vars['node']);

  // Equipment
  _ucrlib_equipment($vars, $vars['node']);

  // Capacity
  _ucrlib_capacity($vars, $vars['node']);
}

/**
 * Implements hook_preprocess_node() for "subject guide".
 */
function ucrlib_preprocess_node__subject_guide(&$vars, $hook) {
  // Carousel
  _ucrlib_carousel($vars, $vars['node']);

  // Course guides
  _ucrlib_course_guides($vars, $vars['node']);

  // Topic guides
  _ucrlib_topic_guides($vars, $vars['node']);

  // Research tool guides
  _ucrlib_research_tool_guides($vars, $vars['node']);

  // Links
  _ucrlib_links($vars, $vars['node']);

  // Databases
  $databases = array();
  $field_databases = _ucrlib_get_field($vars['node'], 'field_databases');
  if (gettype($field_databases) == 'array' && count($field_databases) > 0) {
    foreach ($field_databases as $db) {
    	$node_view = node_view($db['entity'], 'teaser2');
    	$render = render($node_view);
    	$databases[] = $render;
    }
  }
  if (count($databases) > 0) {
    $vars['databases'] = theme('item_list', array('items' => $databases));
  }

  // All databases link
  _ucrlib_subject_specialty($vars, $vars['node']);
  if (isset($vars['subject_specialty']['id'])) {
    $vars['all_databases'] = l(t('See All'), 'research-services/databases',
      array('query' => array('subject_specialties' => $vars['subject_specialty']['id'])));
  }

  // Subject specialists
  $vars['subject_specialists'] = views_embed_view('subject_guide_specialists', 'block_1', $vars['node']->nid);
}


////////////////////////////////////////////////////////////////////////////////
// Helper functions
////////////////////////////////////////////////////////////////////////////////

/**
 * Helper function to render image content.
 */
function _ucrlib_format_picture($node, $field_name, $delta, $picture_group) {
  $image = _ucrlib_get_field($node, $field_name);
  $formatter = array(
    'type' => 'picture',
    'settings' => array(
      'picture_group' => $picture_group,
    ),
  );
  return field_view_value('node', $node, $field_name, $image[$delta], $formatter);
}

/**
 * Sometimes the node/entity has a language identifier on the field, sometimes
 * it does not.
 */
function _ucrlib_get_field($entity, $field_name, $type = 'node') {
// 	dpm($entity);
  if (isset($entity->{$field_name}[0])) {
    return $entity->{$field_name};
  }
  else {
    return field_get_items($type, $entity, $field_name, '');
  }
}
