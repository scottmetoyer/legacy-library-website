(function($, Drupal) {

  "use strict";

  // Main hours page.  This alters the hyper link in the SEE ALL so that a cookie can be set and the correct library is selected
  //when you see the hours of the library.
  Drupal.behaviors.library_hours= {
    attach: function (context, settings) {

    	var intLocation = 0;
		var library = "";
		var url = url = window.location.protocol + "//"+window.location.host+"/library_hours/hours/";
		
		intLocation = document.getElementsByClassName("page-node-65").length;// I want to make sure that the class exists.
		if(0 < intLocation )
		{
			$(".read-more").find("a").attr("href",url+"multimedia");		
		}
		intLocation = document.getElementsByClassName("page-node-105").length;
		if(0 < intLocation )
		{
			$(".read-more").find("a").attr("href",url+"rivera");
		}
		intLocation = document.getElementsByClassName("page-node-107").length;
		if(0 < intLocation )
		{
			$(".read-more").find("a").attr("href",url+"science");			
		}
		intLocation = document.getElementsByClassName("page-node-106").length;
		if(0 < intLocation )
		{
			$(".read-more").find("a").attr("href",url+"music");			
		}
		intLocation = document.getElementsByClassName("page-node-108").length;
		if(0 < intLocation )
		{
			$(".read-more").find("a").attr("href",url+"collections");			
		}
		
    }
  };

})(jQuery, Drupal);
