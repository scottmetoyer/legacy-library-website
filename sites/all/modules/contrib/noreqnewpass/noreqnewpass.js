(function ($) {
  Drupal.behaviors.noreqnewpass = {

		  attach: function(context, settings) {
			  
		    	$(window).ready(function() {
		    		
		    		intLocation = document.getElementsByClassName("section-user").length;
		    		var innerHTML = "";
		    		if(intLocation > 0)
		    		{
		    			innerHTML = document.getElementsByClassName("tabs")[0].innerHTML;
		    			if(""!=innerHTML)
		    			{
			    			innerHTML = innerHTML  + "<li><a href=\"/user/logout\">Log Out </a></li>";
			    			document.getElementsByClassName("tabs")[0].innerHTML = innerHTML;
		    			}
		    		}
		    		
		    	});
		  }
}
  
})(jQuery);