/**
 * 
 * @param $
 * @param Drupal
 * The function below is to change the url to something easier for the end user to remember.  I had to 
 * to do redirects in drupal. Also, this will change the breadcrumbs to the name of the tab.
 */
(function($, Drupal) {

  "use strict";
  Drupal.behaviors.quicktabs_directory = {
    attach: function (context, settings) {
        	var stateObj = {foo: "bar"};
        	var url = window.location.href;
        	var innerHTML = "";
        	var seperator = "<span class=\"breadcrumb__separator\">/</span>";
        	var title = "";    	
        	var finalHTML = "";

        	if(url.indexOf("qt-directory=0")!=-1)
        	{
        		history.replaceState(stateObj, "page 2","/about/directory/department_services");
        		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
        		title = "<span class=\"breadcrumb__page-title\">Departments & Services</span>";
        		finalHTML = innerHTML+seperator+title;
        		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;
        	}
        	else if(url.indexOf("qt-directory=1")!=-1)
        	{    		
        		history.replaceState(stateObj, "page 2","/about/directory/staff");
        		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
        		title = "<span class=\"breadcrumb__page-title\">Staff</span>";
        		finalHTML = innerHTML+seperator+title;
        		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;

        	}
        	else
        	{
        		history.replaceState(stateObj, "page 2","/about/directory/department_services");
        		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
        		title = "<span class=\"breadcrumb__page-title\">Departments & Services</span>";
        		finalHTML = innerHTML+seperator+title;
        		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;        		
        	}
    }
  };

})(jQuery, Drupal);

