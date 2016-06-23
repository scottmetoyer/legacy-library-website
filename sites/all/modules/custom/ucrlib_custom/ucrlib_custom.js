(function($, Drupal) {
//http://library/using-the-library/technology-equipment/equipment
  "use strict";

  // Show (or not) the alert
  Drupal.behaviors.showAlert = {
    attach: function (context, settings) {

    	var digiref = document.getElementById("node-1089");
    	var external_footer = document.getElementsByClassName("page-node-1113").length;
    	var external_header = document.getElementsByClassName("page-node-1130").length;
    	if(digiref===null && external_footer==0 && external_header==0)//We want to show alerts all except for the said node, 
    	{											//which is view/digiref and the external footer.  The external footer is being iframed to other sites.
    	      if (sessionStorage.getItem('ucrlib_custom_alerts')) {
    	          if (sessionStorage.getItem('ucrlib_custom_alerts') == 'enabled') {
    	            insertAlert();
    	          }
    	        }
    	        else {
    	          sessionStorage.setItem('ucrlib_custom_alerts', 'enabled');
    	          insertAlert();
    	        }
    		
    	}

      function insertAlert() {
        if ($('#alert-bar').length === 0) {
          var alertBar = [];
          alertBar.push(
            '<div id="alert-bar" class="alert-bar">',
              '<div class="l-general">',
                '<div class="alert-bar__text">',
                  settings.ucrlibCustom.alertText,
                '</div>',
                '<a id="alert-bar__close" class="alert-bar__close" href="#">Close</a>',
              '</div>',
            '</div>'
          );

          $('body').addClass('with-alert-bar').prepend(alertBar.join(''));

          $('#alert-bar__close').click(function() {
            sessionStorage.setItem('ucrlib_custom_alerts', 'disabled');
            $('#alert-bar').fadeOut();
            return false;
          });
        }
      }

    }
  };

})(jQuery, Drupal);

