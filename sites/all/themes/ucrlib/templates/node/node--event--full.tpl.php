<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="event__content">

    <h1><?php print $title; ?></h1>
<div class="event-float-left">

    <?php if (isset($share)) { ?>
      <div class="event__share">
        <div class="event__share-label"><?php print t('Share'); ?>:</div>
        <?php print $share; ?>
      </div>
    <?php } ?>

    <div class="event__attributes">

      <?php if (isset($event_type)) { ?>
        <div class="event__attribute">
          <span class="event_attribute-label"><?php print t('Event Type'); ?>:</span>
          <span class="event__attribute-content"><?php print $event_type; ?></span>
        </div>
      <?php } ?>

      <?php if (isset($date_links)) { ?>
        <div class="event__attribute">
          <span class="event_attribute-label"><?php print t('Date'); ?>:</span>
          <?php if (count($date_links['links']) > 1) : ?>
            <span class="event__attribute-content">
              <?php print $date_links['links'][0]['date'] . ' - ' . $date_links['links'][count($date_links['links']) - 1]['date']; ?>
            </span>
          <?php else : ?>
            <span class="event__attribute-content">
              <?php print $date_links['links'][0]['date']; ?>
            </span>
          <?php endif; ?>
        </div>
        <div class="event__attribute">
          <span class="event_attribute-label"><?php print t('Time'); ?>:</span>
          <?php if (count($date_links['links']) > 1) : ?>
            <span class="event__attribute-content">Multiple times - see below</span>
          <?php else : ?>
            <span class="event__attribute-content"><?php print $date_links['links'][0]['hours']; ?></span>
          <?php endif; ?>
        </div>
      <?php } ?>
	  <?php if (count($date_links['links']) > 1) : ?>
	  		<span class="event_attribute-label"><?php print t('Location'); ?>:</span>
            <span class="event__attribute-content">Multiple locations - see below</span>
      <?php else : ?>
       <?php if (isset($location)) { ?>
        <div class="event__attribute">
          <span class="event_attribute-label"><?php print t('Location'); ?>:</span>
          <span class="event__attribute-content"><?php print $location; ?></span>
        </div>
		<?php }?>
	  <?php endif; ?>

      <?php if (isset($parking) && count($date_links['links']) == 1) { ?>
        <div class="event__attribute">
          <span class="event_attribute-label"><?php print t('Closest Parking'); ?>:</span>
          <span class="event__attribute-content"><?php print $parking; ?></span>
        </div>
      <?php } ?>

    </div>

    <?php if (isset($content['body'])) { ?>
      <h2><?php print t('Description'); ?></h2>
      <?php print render($content['body']); ?>
    <?php } ?>

    <?php if (isset($instructors)) : ?>
      <h2><?php print t('Instructors'); ?></h2>
      <div class="event__instructors">
        <?php foreach ($instructors as $instructor) { ?>
          <div class="event__instructor">
            <div class="event__instructor-name"><?php print $instructor['person_name']; ?></div>
            <div class="event__instructor-job-title"><?php print $instructor['person_job_title']; ?></div>
            <div class="event__instructor-phone"><?php print $instructor['person_phone']; ?></div>
            <div class="event__instructor-email"><?php print $instructor['person_email']; ?></div>
          </div>
        <?php } ?>
      </div>
    <?php endif; ?>

    <?php if (isset($links_list)) : ?>
      <div class="event__related related">
        <h3 class="related__title"><?php print t('Related Information'); ?></h3>
        <div class="related__content">
          <?php print $links_list; ?>
        </div>
      </div>
    <?php endif; ?>
	</div>
	<div class="event-float-right">
		<aside class="event-block cta">
      <h3 class="cta__title">Sign up for UCR Library News</h3>
      <div class="cta__content"><p><a href="http://ucr.us10.list-manage.com/subscribe?u=3d3292965cebf17f0755f5ae2&id=7c4e1e6d46">Click here to sign up today!</a></p>
</div>
    </aside>
	</div>
	<div class="event-clear-both">
	</div>
  </div>

  <aside class="event__sidebar-first">

    <?php if (isset($content['field_image'])) : ?>
      <?php print render($content['field_image']); ?>
    <?php else : ?>
      <div class="event__image">
        <img src="/<?php print $default_images['event']; ?>" alt="" />
      </div>
    <?php endif; ?>

    <div class="event__sidebar-section">
      <h3 class="event__sidebar-section-title"><?php print t('RSVP'); ?></h3>
      <div class="event__sidebar-section-content">
        <?php if ($event_rsvp_text) { ?>
          <?php if ($date_links['type'] == 'grouped') : ?>
            <div class="event__rsvp-text event__rsvp-text--grouped">
              <?php print $event_rsvp_text; ?>
              <div class="event__rsvp-link">
                <a href="<?php print $date_links['links'][0]['link']; ?>"><?php print t('RSVP'); ?></a>
              </div>
            </div>
          <?php elseif (count($date_links['links']) == 1) : ?>
            <div class="event__rsvp-text event__rsvp-text--single"><?php print $event_rsvp_text; ?></div>
          <?php else : ?>
            <div class="event__rsvp-text event__rsvp-text--multiple"><?php print $event_rsvp_text; ?></div>
          <?php endif; ?>
        <?php } ?>

        <?php if ($date_links['type'] == 'grouped') : ?>
          <?php foreach ($date_links['links'] as $date_link) { ?>
            <div class="event__rsvp-row event__rsvp-row--grouped">
              <div class="event__rsvp-date">
                <?php print $date_link['date']; ?>
              </div>
              <div class="event__rsvp-hours">
                <?php print $date_link['hours']; ?>
              </div>
            </div>
          <?php } ?>
        <?php elseif (count($date_links['links']) == 1) : ?>
          <div class="event__rsvp-row event__rsvp-row--single">
            <div class="event__rsvp-link">
              <a href="<?php print $date_links['links'][0]['link']; ?>"><?php print t('RSVP'); ?></a>
            </div>
          </div>
        <?php else : ?>
          <?php foreach ($date_links['links'] as $date_link) { ?>
            <div class="event__rsvp-row event__rsvp-row--multiple">
              <div class="event__rsvp-date-hours">
                <div class="event__rsvp-date">
                  <?php print $date_link['date']; ?>
                </div>
                <div class="event__rsvp-hours">
                  <?php print $date_link['hours']; ?>
                </div>
				<hr width="95%" align="left">
                <div class="event__rsvp-library-name">
                <?php print $library_name; ?>
                </div>
              <div class="event__rsvp-room">Room:
                <?php print $library_room; ?>
                </div>

              </div>
              <div class="event__rsvp-link">
                <a href="<?php print $date_link['link']; ?>"><?php print t('RSVP'); ?></a>
              </div>
               	<div class="event__rsvp-cb">
				</div>

            </div>
          <?php } ?>
        <?php endif; ?>

      </div>
    </div>

    <?php if (isset($person_name)) { ?>
      <div class="event__sidebar-section">
        <h3 class="event__sidebar-section-title"><?php print t('Contact Person'); ?></h3>
        <div class="event__sidebar-section-content">
          <div class="event__contact-person-name"><?php print $person_name; ?></div>
          <div class="event__contact-person-job-title"><?php print $person_job_title; ?></div>
          <div class="event__contact-person-phone"><?php print $person_phone; ?></div>
          <div class="event__contact-person-email"><?php print $person_email; ?></div>
        </div>
      </div>
    <?php } ?>

  </aside>


</article>
