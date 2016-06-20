/**
 * 
 *
 * 
 */
(function($, Drupal){
  "use strict";
  Drupal.behaviors.calendar = {
    attach: function (context, settings) {
    	if(document.getElementsByClassName("form-item form-type-advanced-link form-item-field-event-date-links-und-0-field-link-und-0").length>0)
    	{
        	var tempInnerHTML = document.getElementsByClassName("form-item form-type-advanced-link form-item-field-event-date-links-und-0-field-link-und-0")[0].innerHTML;
        	var innerHTML = tempInnerHTML.replace("RSVP link", "Link");
        	document.getElementsByClassName("form-item form-type-advanced-link form-item-field-event-date-links-und-0-field-link-und-0")[0].innerHTML = innerHTML;    		
    	}
    }
  }
})(jQuery, Drupal);

