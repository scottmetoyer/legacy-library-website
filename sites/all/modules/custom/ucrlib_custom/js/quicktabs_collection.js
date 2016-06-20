/**
 * 
 * @param $
 * @param Drupal
 * The function below is to change the url to something easier for the end user to remember.  I had to 
 * to do redirects in drupal. Also, this will change the breadcrumbs to the name of the tab.
 */
(function($, Drupal) {

  "use strict";
  Drupal.behaviors.quicktabs_collection = {
    attach: function (context, settings) {
    	var stateObj = {foo: "bar"};
    	var url = window.location.href;
    	var innerHTML = "";
    	var seperator = "<span class=\"breadcrumb__separator\">/</span>";
    	var title = "";
    	var subjectAreas = "<span class=\"breadcrumb__page-title\">Collecting Areas</span>";
    	var finalHTML = "";
    	if(url.indexOf("qt-collections=1")!=-1 && url.indexOf("qt-collections_subject_areas=1")!=-1)
    	{
    		history.replaceState(stateObj, "page 2","/collections/collecting-areas/agriculture");
    		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
    		title = "<span class=\"breadcrumb__page-title\">Agriculture</span>";
    		finalHTML = innerHTML+seperator+subjectAreas+seperator+title;
    		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;
    	}
    	else if(url.indexOf("qt-collections=1")!=-1 && url.indexOf("qt-collections_subject_areas=2")!=-1)
    	{    		
    		history.replaceState(stateObj, "page 2","/collections/collecting-areas/business-education-public-policy");
    		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
    		title = "<span class=\"breadcrumb__page-title\">Business, Education & Public Policy</span>";
    		finalHTML = innerHTML+seperator+subjectAreas+seperator+title;
    		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;
    	}
    	else if(url.indexOf("qt-collections=1")!=-1 && url.indexOf("qt-collections_subject_areas=3")!=-1)
    	{
    		history.replaceState(stateObj, "page 2","/collections/collecting-areas/science-technology-engineering-math-and-medicine");
    		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
    		title = "<span class=\"breadcrumb__page-title\">Science, Technology, Engineering, Math & Medicine</span>";
    		finalHTML = innerHTML+seperator+subjectAreas+seperator+title;
    		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;
    	}
    	else if(url.indexOf("qt-collections=1")!=-1 && url.indexOf("qt-collections_subject_areas=4")!=-1)
    	{
    		history.replaceState(stateObj, "page 2","/collections/collecting-areas/social-sciences");
    		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
    		title = "<span class=\"breadcrumb__page-title\">Social Sciences</span>";
    		finalHTML = innerHTML+seperator+subjectAreas+seperator+title;
    		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;    		
    	}
    	else if(url.indexOf("qt-collections=1")!=-1)
    	{
    		history.replaceState(stateObj, "page 2","/collections/collecting-areas/arts-humanities");
    		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
    		title = "<span class=\"breadcrumb__page-title\">Arts Humanities</span>";
    		finalHTML = innerHTML+seperator+subjectAreas+seperator+title;
    		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;    		
    	}
    	else if(url.indexOf("qt-collections=0")!=-1)
    	{
    		history.replaceState(stateObj, "page 2","/collections/notable-collections");
    		innerHTML = document.getElementsByClassName("breadcrumb")[0].innerHTML;
    		title = "<span class=\"breadcrumb__page-title\">Notable Collections</span>";
    		finalHTML = innerHTML+seperator+title;
    		document.getElementsByClassName("breadcrumb")[0].innerHTML = finalHTML;    		
    	}
    }
  };

})(jQuery, Drupal);

