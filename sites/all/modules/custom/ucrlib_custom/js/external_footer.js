/**
 * 
 */

(function($, Drupal) {

  "use strict";
  Drupal.behaviors.exteranFooter = {
    attach: function (context, settings) {
    	var external_footer = document.getElementsByClassName("page-node-1113").length;
    	if(external_footer>0)
    	{
        	var anchors = document.getElementsByTagName("a");
        	var size =anchors.length;
        	var i =0;
        	for (i=0; i<size; i++){ 
        		anchors[i].setAttribute("target","_blank");
        	}    	
    		
    	}
    }
  };

})(jQuery, Drupal);

