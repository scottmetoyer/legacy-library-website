<?php

/**
 * @file
 * Common fields shared among multiple node types.
 */

function _ucrlib_ada_info(&$return, $entity) {
  $link = _ucrlib_get_field($entity, 'field_ada_info');

  $return['ada_info'] = NULL;
  if (isset($link[0]['url'])) {
    $return['ada_info'] = l($link[0]['title'], $link[0]['url']);
  }
}

function _ucrlib_address1(&$return, $entity) {
  $address = _ucrlib_get_field($entity, 'field_address1');

  $return['address1'] = isset($address[0]['value']) ? nl2br($address[0]['value']) : NULL;
}

function _ucrlib_address2(&$return, $entity) {
  $address = _ucrlib_get_field($entity, 'field_address2');

  $return['address2'] = isset($address[0]['value']) ? nl2br($address[0]['value']) : NULL;
}

function _ucrlib_capacities(&$return, $entity) {
  $capacities = array();

  $field_capacities = _ucrlib_get_field($entity, 'field_capacities');
  if (gettype($field_capacities) == 'array' && count($field_capacities) > 0) {
    foreach ($field_capacities as $item) {
      $capacities[] = $item['value'];
    }
  }

  if (count($capacities) > 0) {
    $return['capacities'] = theme('item_list', array('items' => $capacities));
  }
}

function _ucrlib_capacity(&$return, $entity) {
  $capacity = _ucrlib_get_field($entity, 'field_capacity');

  $return['capacity'] = isset($capacity[0]['value']) ? $capacity[0]['value'] : NULL;
}

function _ucrlib_carousel(&$return, $entity) {
  $carousel_width = _ucrlib_get_field($entity, 'field_carousel_width');

  $fc_ids = array();
  $field_carousel = _ucrlib_get_field($entity, 'field_carousel');
  if (gettype($field_carousel) == 'array' && count($field_carousel) > 0) {
    foreach ($field_carousel as $item) {
      $fc_ids[] = $item['value'];
    }
  }

  $carousel = array();
  $carousel_items = entity_load('field_collection_item', $fc_ids);
  if (gettype($carousel_items) == 'array' && count($carousel_items) > 0) {
    foreach ($carousel_items as $carousel_item) {
      $image_arr = _ucrlib_get_field($carousel_item, 'field_image', 'field_collection_item');
      if (isset($image_arr[0]['uri'])) {
        $caption_arr = _ucrlib_get_field($carousel_item, 'field_caption', 'field_collection_item');
        $caption = '';
        if (isset($caption_arr[0]['value'])) {
          $caption = $caption_arr[0]['value'];
        }

        $image = theme('image_style', array('path' => $image_arr[0]['uri'], 'style_name' => 'carousel_item', 'attributes' => array('title' => $caption)));

        $carousel[] = $image;
      }
    }
  }

  if (count($carousel) > 0) {
    $return['carousel'] = theme('item_list', array('items' => $carousel));
    $return['carousel_width'] = $carousel_width[0]['value'];
  }
}

function _ucrlib_collections(&$return, $entity) {
  $collections = array();

  $field_collections = _ucrlib_get_field($entity, 'field_collections');
  if (gettype($field_collections) == 'array' && count($field_collections) > 0) {
    foreach ($field_collections as $item) {
      if (isset($item['entity']->title)) {
        $collections[] = l($item['entity']->title, 'node/' . $item['target_id']);
      }
    }
  }

  if (count($collections) > 0) {
    $return['collections'] = theme('item_list', array('items' => $collections));
  }
}

function _ucrlib_color(&$return, $entity) {

	$return["color"] = null;
	if(isset($entity->field_event_type['und'][0]['tid']))
	{
		$tid=$entity->field_event_type['und'][0]['tid'];

		$db_query = db_select('field_data_field_color','f')
		->condition("entity_id",$tid)
		->fields('f',array('field_color_rgb'));
		$result = $db_query->execute();

		while($record = $result->fetchAssoc())
		{
			$color = $record['field_color_rgb'];
		}
		$return["color"]=$color;
	}
}

function _ucrlib_course_guides(&$return, $entity) {
  $links = array();

  $field_course_guides = _ucrlib_get_field($entity, 'field_course_guides');
  if (gettype($field_course_guides) == 'array' && count($field_course_guides) > 0) {
    foreach ($field_course_guides as $link) {
      $links[] = l(
        $link['title'],
        ltrim($link['url'], '/'),  // Remove leading "/" if user put it there
        array('attributes' => $link['attributes'])
      );
    }
  }

  if (count($links) > 0) {
    $return['course_guides'] = theme('item_list', array('items' => $links));
  }
}

function _ucrlib_date(&$return, $entity, $format = 'F j, Y', $type = 'node') {
  $date = _ucrlib_get_field($entity, 'field_date', $type);

  $return['date'] = NULL;
  if (isset($date[0]['value'])) {
    $time = strtotime($date[0]['value']);
    $return['raw_time'] = $time;
    $return['date'] = date($format, $time);
  }
}

function _ucrlib_default_images(&$return, $entity) {
  $return['default_images']['event'] = drupal_get_path('theme', 'ucrlib') . '/images/default-event.png';
  $return['default_images']['news'] = drupal_get_path('theme', 'ucrlib') . '/images/default-news.png';
  $return['default_images']['news_square'] = drupal_get_path('theme', 'ucrlib') . '/images/default-news-square.png';
  $return['default_images']['person'] = drupal_get_path('theme', 'ucrlib') . '/images/default-person.png';
}

function _ucrlib_department_hours(&$return, $entity) {
  $hours = _ucrlib_get_field($entity, 'field_dept_hours');

  $return['hours'] = NULL;
  if (isset($hours[0]['value'])) {
    $return['hours'] = $hours[0]['value'];
  }
}

function _ucrlib_email(&$return, $entity) {
  $email = _ucrlib_get_field($entity, 'field_email');

  $return['email'] = NULL;
  if (isset($email[0]['email'])) {
    $return['email'] = l('Email', 'mailto:' . $email[0]['email'], array('absolute' => TRUE));
  }
}

function _ucrlib_equipment(&$return, $entity) {
  $equipment = array();

  $field_equipment = _ucrlib_get_field($entity, 'field_equipment');
  if (gettype($field_equipment) == 'array' && count($field_equipment) > 0) {
    foreach ($field_equipment as $item) {
      $equipment[] = $item['taxonomy_term']->name;
    }
  }

  if (count($equipment) > 0) {
    $return['equipment'] = theme('item_list', array('items' => $equipment));
  }
}

function _ucrlib_event_date_links(&$return, $entity) {
  $fc_ids = array();
  $field_event_date_links = _ucrlib_get_field($entity, 'field_event_date_links');
  if (gettype($field_event_date_links) == 'array' && count($field_event_date_links) > 0) {
    foreach ($field_event_date_links as $item) {
      $fc_ids[] = $item['value'];
    }
  }

  $link = _ucrlib_get_field($entity, 'field_link');
  if (isset($link[0]['url'])) {
    $return['date_links']['type'] = 'grouped';
    $return['date_links']['grouped_link'] = $link[0]['url'];
  }
  else {
    $return['date_links']['type'] = 'individual';
  }

  $date_links = array();
  $date_links_items = entity_load('field_collection_item', $fc_ids);
  foreach ($date_links_items as $date_links_item) {
  	$date_link = array();
    _ucrlib_link($date_link, $date_links_item, 'field_collection_item');
    _ucrlib_date($date_link, $date_links_item, 'M j, Y', 'field_collection_item');
    _ucrlib_hours($date_link, $date_links_item, 'field_collection_item');
    _ucrlib_library($date_link, $date_links_item, 'field_collection_item');
    _ucrlib_room($date_link, $date_links_item, 'field_collection_item');
    _ucrlib_event_type($date_link,$date_links_item);
    _ucrlib_color($date_link, $date_links_item);
    $date_links[] = $date_link;
  }

  // Sort by date
  
  usort($date_links, function($a, $b) {
    return $a['raw_time'] - $b['raw_time'];
  });

  $return['date_links']['links'] = $date_links;

}

function _ucrlib_event_type(&$return, $entity) {
	$return['event_type'] = NULL;
	$eventName = "";
	if(isset($entity->field_event_type))
	{
		if(array_key_exists('und',$entity->field_event_type))
		{
			$tid=$entity->field_event_type['und'][0]['tid'];
			$eventName = "";
			$db_query = db_select('taxonomy_term_data','t')
			->condition("tid",$tid)
			->fields('t',array('name'));
			$result = $db_query->execute();

			while($record = $result->fetchAssoc())
			{
				$eventName = $record['name'];
			}
		}
		$return['event_type'] = $eventName;
	}
}

function _ucrlib_fax(&$return, $entity) {
  $fax = _ucrlib_get_field($entity, 'field_fax');

  $return['fax'] = NULL;
  if (isset($fax[0]['value'])) {
    $return['fax'] = $fax[0]['value'];
  }
}

function _ucrlib_features(&$return, $entity) {
  $features = array();
  foreach ($return['field_study_space_features'] as $feature) {
    $features[] = $feature['taxonomy_term']->name;
  }
  if (count($features) > 0) {
    $return['features'] = theme('item_list', array('items' => $features));
  }
}

function _ucrlib_floor(&$return, $entity) {
  $floor = _ucrlib_get_field($entity, 'field_floor');
  $return['floor'] = isset($floor[0]['value']) ? $floor[0]['value'] : '';
}

function _ucrlib_guides(&$return, $entity) {
  $guides = array();

  $field_guides = _ucrlib_get_field($entity, 'field_guides');
  if (gettype($field_guides) == 'array' && count($field_guides) > 0) {
    foreach ($field_guides as $item) {
      if (isset($item['entity']->title)) {
        $guides[] = l($item['entity']->title, 'node/' . $item['target_id']);
      }
    }
  }

  if (count($guides) > 0) {
    $return['guides'] = theme('item_list', array('items' => $guides));
  }
}

function _ucrlib_google_directions(&$return, $entity) {
  $address = _ucrlib_get_field($entity, 'field_google_map_address');

  $return['google_directions'] = NULL;
  if (isset($address[0]['value'])) {
    $return['google_directions'] = l('Google Maps', 'http://maps.google.com/maps?saddr=&daddr="' . $address[0]['value'] . '"');
  }
}

function _ucrlib_hours(&$return, $entity, $type = 'node') {
  $hours = _ucrlib_get_field($entity, 'field_hours', $type);

  if (isset($hours[0]['value_formatted']) && isset($hours[0]['value2_formatted'])) {
    $return['hours'] = $hours[0]['value_formatted'] . ' - ' . $hours[0]['value2_formatted'];
  }
  elseif (isset($hours[0]['value_formatted'])) {
    $return['hours'] = $hours[0]['value_formatted'];
  }
  elseif (isset($hours[0]['value2_formatted'])) {
    $return['hours'] = $hours[0]['value2_formatted'];
  }
  else {
    $return['hours'] = NULL;
  }
}

function _ucrlib_job_title(&$return, $entity) {
  $job_title = _ucrlib_get_field($entity, 'field_job_title');
  $return['job_title'] = isset($job_title[0]['value']) ? $job_title[0]['value'] : NULL;
}

function _ucrlib_department(&$return, $entity) {
	$nid = _ucrlib_get_field($entity, 'field_department');
	$href = "/node/".$nid[0]['target_id'];
	$db_query = null;
	$results = null;
	$return['departments'] = null;
	$db_query = db_select('node','n')
	->condition("nid",$nid[0]['target_id'])
	->fields('n',array('title'));
	$result = $db_query->execute();
	$title = null;
	while($record = $result->fetchAssoc())
	{
		$title = $record['title'];
	}
	if($title!=null)
	{
		$return['department'] = "<a href=$href>".$title."</a>";
	}

}

function _ucrlib_departments(&$return, $entity) {
	$nid = _ucrlib_get_field($entity, 'field_departments');
	$size = 0;
	$size = sizeof($nid);
	$db_query = null;
	$results = null;
	$return['departments'] = null;
	$lastCall = $size - 1;
	$href = "";
	$snippet = "";
	$title = null;
 	$html = "";
	$db_query = db_select('node','n')
	->fields('n',array('title'));
	for($i=0; $i<$size; $i++)
	{
		if($i!=$lastCall)
		{
			$snippet .= " nid='".$nid[$i]['target_id']. "' OR";
		}
		else
		{
			$snippet .= " nid='".$nid[$i]['target_id']."'";
		}

	}
	$db_query->where($snippet);
	$result = $db_query->execute();
	$i=0;
	while($record = $result->fetchAssoc())
	{
		$title = $record['title'];
		$href = "/node/".$nid[$i]['target_id'];
		if($i!=$lastCall)
		{
			$html .="<a href=$href>".$title."</a>, ";
		}
		else
		{
			$html .="<a href=$href>".$title."</a>";
		}
		$i++;
	}

	$return['departments'] = $html;
}


function _ucrlib_libraries(&$return, $entity) {
  $libraries = _ucrlib_get_field($entity, 'field_libraries');
  $return['libraries'] = array();
  if (gettype($libraries) == 'array' && count($libraries) > 0) {
    foreach ($libraries as $library_item) {
      $library = isset($library_item['entity']) ? $library_item['entity'] : node_load($library_item['target_id']);
      $return['libraries'][] = l($library->title, 'node/' . $library->nid);
    }
  }
}

function _ucrlib_library(&$return, $entity, $type='node') {
  $library = _ucrlib_get_field($entity, 'field_library', $type);
  $return['library'] = NULL;
  $return['library_id'] = 0;
  $return['library_name'] = '';
  $return['field_parking'] = NULL;

  if (isset($library[0]['entity'])) {
    $return['library_id'] = $library[0]['target_id'];
    $return['library_name'] = $library[0]['entity']->title;
    $return['library'] = l($library[0]['entity']->title, 'node/' . $library[0]['target_id']);
    $return['field_parking']['title'] =  $library[0]['entity']->field_parking['und'][0]['title'];
    $return['field_parking']['url'] = $library[0]['entity']->field_parking['und'][0]['url'];
  }
  else if(isset($library[0]['target_id']))
  {//This is for the teaser views
  	$libraryName = "";
  	$nid=$library[0]['target_id'];

  	$db_query = db_select('node','n')
  	->condition("nid",$nid)
  	->fields('n',array('title'));
  	$result = $db_query->execute();

  	while($record = $result->fetchAssoc())
  	{
  		$libraryName = $record['title'];
  	}
  	$return['library_name'] = $libraryName;
  }

}

function _ucrlib_link(&$return, $entity, $type = 'node') {
  $link = _ucrlib_get_field($entity, 'field_link', $type);

  $return['link'] = isset($link[0]['url']) ? $link[0]['url'] : NULL;
}

function _ucrlib_links(&$return, $entity) {
  $links = array();

  $field_links = _ucrlib_get_field($entity, 'field_links');
  if (gettype($field_links) == 'array' && count($field_links) > 0) {
    foreach ($field_links as $link) {
      $links[] = l(
        decode_entities($link['title']),
        ltrim($link['url'], '/'),  // Remove leading "/" if user put it there
        array('attributes' => $link['attributes'])
      );
    }
  }

  if (count($links) > 0) {
    $return['links_list'] = theme('item_list', array('items' => $links));
  }
}

function _ucrlib_map(&$return, $entity) {
  $map = _ucrlib_get_field($entity, 'field_map', 'node');
  $return['map'] = isset($map[0]['target_id']) ? url('node/' . $map[0]['target_id']) : NULL;
}

function _ucrlib_parking(&$return, $entity) {
  $return['parking'] = NULL;
  if (isset($return['date_links']['links'][0]['field_parking']['title'])&&
  		isset($return['date_links']['links'][0]['field_parking']['url'])) {
    $return['parking'] = l($return['date_links']['links'][0]['field_parking']['title'], $return['date_links']['links'][0]['field_parking']['url']);
  }
}

function _ucrlib_people(&$return, $entity) {
  $people = _ucrlib_get_field($entity, 'field_people');

  $return['people'] = array();
  if (isset($people[0]['target_id'])) {
    foreach ($people as $person_item) {
      $person = array();
      $person_entity = isset($person_item['entity']) ? $person_item['entity'] : node_load($person_item['target_id']);
      _ucrlib_person_data($person, $person_entity);
      $return['people'][] = $person;
    }
  }
}

function _ucrlib_person(&$return, $entity) {
  $person = _ucrlib_get_field($entity, 'field_person');

  if (isset($person[0]['entity']->title)) {
    _ucrlib_person_data($return, $person[0]['entity']);
  }
}


function _ucrlib_person_data(&$return, $person) {
  $return['person_name'] = l($person->title, 'node/' . $person->nid);

  $return['person_photo'] = NULL;
  $person_photo = _ucrlib_get_field($person, 'field_image');
  if (isset($person_photo[0]['uri'])) {
    $img = theme('image_style', array('path' => $person_photo[0]['uri'], 'style_name' => 'person_thumb'));
    $return['person_photo'] = l($img, 'node/' . $person->nid, array('html' => TRUE));
  }

  $return['person_job_title'] = NULL;
  $person_job = _ucrlib_get_field($person, 'field_job_title');
  if (isset($person_job[0]['value'])) {
    $return['person_job_title'] = $person_job[0]['value'];
  }

  $return['person_phone'] = NULL;
  $person_phone = _ucrlib_get_field($person, 'field_phone');
  if (isset($person_phone[0]['value'])) {
    $return['person_phone'] = l($person_phone[0]['value'], 'tel:' . $person_phone[0]['value'], array('absolute' => TRUE));
  }

  $return['person_email'] = NULL;
  $person_email = _ucrlib_get_field($person, 'field_email');
  if (isset($person_email[0]['email'])) {
    $return['person_email'] = l('Email', 'mailto:' . $person_email[0]['email'], array('absolute' => TRUE));
  }
}


function _ucrlib_phone(&$return, $entity) {
  $phone = _ucrlib_get_field($entity, 'field_phone');

  $return['phone'] = NULL;
  if (isset($phone[0]['value'])) {
    $return['phone'] = l($phone[0]['value'], 'tel:' . $phone[0]['value'], array('absolute' => TRUE));
  }
}

function _ucrlib_email_library(&$return, $entity) {
	$email = _ucrlib_get_field($entity, 'field_email_library');
	$return['email'] = NULL;
	if (isset($email[0]['email'])) {

		if($email[0]['email']!=null && $email[0]['email']!="")
		{
			$return['email'] = $email[0]['email'];
		}

	}
}


function _ucrlib_public_transit(&$return, $entity) {
  $link = _ucrlib_get_field($entity, 'field_public_transit');

  $return['public_transit'] = NULL;
  if (isset($link[0]['url'])) {
    $return['public_transit'] = l($link[0]['title'], $link[0]['url']);
  }
}
function _ucrlib_research_tool_guides(&$return, $entity) {
  $links = array();

  $field_research_tool_guides = _ucrlib_get_field($entity, 'field_research_tool_guides');
  if (gettype($field_research_tool_guides) == 'array' && count($field_research_tool_guides) > 0) {
    foreach ($field_research_tool_guides as $link) {
      $links[] = l(
        $link['title'],
        ltrim($link['url'], '/'),  // Remove leading "/" if user put it there
        array('attributes' => $link['attributes'])
      );
    }
  }

  if (count($links) > 0) {
    $return['research_tool_guides'] = theme('item_list', array('items' => $links));
  }
}

function _ucrlib_room(&$return, $entity, $type='node') {
  $room = _ucrlib_get_field($entity, 'field_room', $type);


  $return['room'] = isset($room[0]['value']) ? $room[0]['value'] : NULL;
}

function _ucrlib_share(&$return, $entity) {
  $buttons = '<div class="st_facebook_large" displayText="Facebook"></div>';
  $buttons .= '<div class="st_twitter_large" displayText="Tweet"></div>';
  $buttons .= '<div class="st_email_large" displayText="Email"></div>';
  $buttons .= '<div class="st_print_large" displayText="Print"></div>';

  drupal_add_js('var switchTo5x=true;', 'inline');
  drupal_add_js('http://w.sharethis.com/button/buttons.js', 'external');
  drupal_add_js('stLight.options({publisher: "a6e4c48f-c95e-40e9-b428-5dfc2d7e6183", doNotHash: false, doNotCopy: false, hashAddressBar: false});', 'inline');
  $return['share'] = $buttons;
}

function _ucrlib_short_description(&$return, $entity) {
  $description = _ucrlib_get_field($entity, 'field_short_description');

  $return['description'] = isset($description[0]['value']) ? $description[0]['value'] : NULL;
}

function _ucrlib_sidebar_cta(&$return, $entity) {
  if (isset($return['field_cta_title'][0]['value']) && isset($return['field_cta_content'][0]['value'])) {
    $return['classes_array'][] = 'with-cta';
    $return['cta_title'] = $return['field_cta_title'][0]['value'];
    $return['cta_content'] = $return['field_cta_content'][0]['value'];
  }
  elseif (isset($return['field_cta_content'][0]['value'])) {
    $return['classes_array'][] = 'with-cta';
    $return['cta_content'] = $return['field_cta_content'][0]['value'];
  }
}

function _ucrlib_subject_areas(&$return, $entity) {
  $subjects = array();

  $subjects_field = _ucrlib_get_field($entity, 'field_subject_areas');
  if (gettype($subjects_field) == 'array' && count($subjects_field) > 0) {
    foreach ($subjects_field as $subject) {
      if (!isset($subject['taxonomy_term'])) {
        $subject['taxonomy_term'] = taxonomy_term_load($subject['tid']);
      }
      $subjects[] = $subject['taxonomy_term']->name;
    }
  }

  if (count($subjects) > 0) {
    $return['subjects'] = theme('item_list', array('items' => $subjects));
  }
}

function _ucrlib_subject_specialties(&$return, $entity) {
  $subjects = array();

  $field_subject_specialties = _ucrlib_get_field($entity, 'field_subject_specialties');
  if (gettype($field_subject_specialties) == 'array' && count($field_subject_specialties) > 0) {
    foreach ($field_subject_specialties as $subject) {
      if (!isset($subject['taxonomy_term'])) {
        $subject['taxonomy_term'] = taxonomy_term_load($subject['tid']);
      }
      $subjects[] = $subject['taxonomy_term']->name;
    }
  }

  if (count($subjects) > 0) {
    $return['subject_specialties'] = theme('item_list', array('items' => $subjects));
  }
}

function _ucrlib_subject_specialty(&$return, $entity) {
  $subject_specialty = _ucrlib_get_field($entity, 'field_subject_specialty');
  $field_equipment = _ucrlib_get_field($entity, 'field_equipment');
  if (gettype($subject_specialty) == 'array' && count($subject_specialty) > 0) {
    $return['subject_specialty']['id'] = $subject_specialty[0]['tid'];
  }
  else {
    $return['subject_specialty']['id'] = NULL;
  }
}

function _ucrlib_text_list(&$return, $entity, $name) {
  $list = array();

  $field_text_list = _ucrlib_get_field($entity, 'field_text_list');
  if (gettype($field_text_list) == 'array' && count($field_text_list) > 0) {
    foreach ($field_text_list as $item) {
      $list[] = $item['value'];
    }
  }

  if (count($list) > 0) {
    $return[$name] = theme('item_list', array('items' => $list));
  }
}

function _ucrlib_topic_guides(&$return, $entity) {
  $links = array();

  $field_topic_guides = _ucrlib_get_field($entity, 'field_topic_guides');
  if (gettype($field_topic_guides) == 'array' && count($field_topic_guides) > 0) {
    foreach ($field_topic_guides as $link) {
      $links[] = l(
        $link['title'],
        ltrim($link['url'], '/'),  // Remove leading "/" if user put it there
        array('attributes' => $link['attributes'])
      );
    }
  }

  if (count($links) > 0) {
    $return['topic_guides'] = theme('item_list', array('items' => $links));
  }
}

function _ucrlib_trial(&$return, $entity) {
  $bool = _ucrlib_get_field($entity, 'field_trial');

  $return['is_trial'] = NULL;
  if (isset($bool[0]['value'])) {
    $return['is_trial'] = $bool[0]['value'];
  }
}

function _ucrlib_type_of_access(&$return, $entity) {
	$return['type_of_access'] = isset($entity->field_type_of_access['und'][0]['value']) ? $entity->field_type_of_access['und'][0]['value'] : NULL;

}


function _ucrlib_trial_end_date(&$return, $entity) {
  $date = _ucrlib_get_field($entity, 'field_trial_end_date');

  $return['trial_end_date'] = NULL;
  if (isset($date[0]['value'])) {
    $time = strtotime($date[0]['value']);
    $return['raw_time'] = $time;
    $return['trial_end_date'] = date('n/j/Y', $time);
  }
}

function _ucrlib_very_short_description(&$return, $entity) {
  $description = _ucrlib_get_field($entity, 'field_very_short_description');

  $return['description'] = isset($description[0]['value']) ? $description[0]['value'] : NULL;
}
