/**
 * The purpose of this javascript is to change the look and feel of the buttons.  I wasn't able 
 * to change the look and feel because its part of the webform module in drupal.  Since
 * I only wanted to change the look for one form or node, this was the path of least resistance.
 */
(function($, Drupal){

  "use strict";
  Drupal.behaviors.request_library_instruction_session = {
    attach: function (context, settings) {
     	
    	$(window).ready(function() {  
    		$('label[for=edit-submitted-class-syllabus-upload]').remove();
    		document.getElementsByClassName("form-file")[0].style.visibility = "hidden";
        	var innerHTML = document.getElementsByClassName("class_syllabus")[0];
        	var frommanagefile = innerHTML.getElementsByClassName("form-managed-file")[0].innerHTML;
        	var description = "<div class=\"description\">"+innerHTML.getElementsByClassName("description")[0].innerHTML+"</div>";
        	var floatLeft = "<div class=\"table-lib-instruction-session\"><div class=\"float-left-lib-instruction-session\">" +
        			"			<label>Class Syllabus</label>" +
        			"		<label for=\"edit-submitted-class-syllabus-upload\" class=\"lib-instruction-session_Btn\">Choose File</label>"+
        				"<div value=\"Choose File\" pseudo=\"-webkit-file-upload-button\"></div></div>";
        	var floatRight = "<div class=\"float-right-lib-instruction-session\">"+frommanagefile +"</div>";
        	var floatCB = "<div class=\"clear-both-lib-instruction-session\"></div></div>";
        	document.getElementsByClassName("class_syllabus")[0].innerHTML =floatLeft + floatRight + floatCB + description;

    		$('label[for=edit-submitted-assignment-upload]').remove();
    		document.getElementsByClassName("form-file")[1].style.visibility = "hidden";
        	innerHTML = document.getElementsByClassName("assi")[0];
        	frommanagefile = innerHTML.getElementsByClassName("form-managed-file")[0].innerHTML;
        	description = "<div class=\"description\">"+innerHTML.getElementsByClassName("description")[0].innerHTML+"</div>";
        	floatLeft = "<div class=\"table-lib-instruction-session\"><div class=\"float-left-lib-instruction-session\">" +
        			"			<label>Assignment</label>" +
        			"		<label for=\"edit-submitted-lib-instruction-session-upload\" class=\"lib-instruction-session_Btn\">Choose File</label>"+
        				"<div value=\"Choose File\" pseudo=\"-webkit-file-upload-button\"></div></div>";
        	floatRight = "<div class=\"float-right-lib-instruction-session\">"+frommanagefile +"</div>";
        	floatCB = "<div class=\"clear-both-lib-instruction-session\"></div></div>";
        	document.getElementsByClassName("assi")[0].innerHTML =floatLeft + floatRight + floatCB + description;
    	});
    }
  }
})(jQuery, Drupal);
