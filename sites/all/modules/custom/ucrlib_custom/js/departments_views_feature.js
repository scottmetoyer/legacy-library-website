/**
 * The purpose of this javascript is automatically input the department name in the combo box when the page is loaded.
 * 
 */
(function ($) {
	Drupal.behaviors.departments_views_feature = 
	{
			attach: function(context, settings) 
			{
		    	$(window).ready(function(){    		    		
		    			var obj = document.getElementById("edit-field-department-und");
		    			if(obj!=null)
		    			{
			    			var url 	= document.URL;//This is the url of the web page.  Drupal puts the id of the department at the end of the url
			    			var departmentName = "";
		    				var options = document.getElementById("edit-field-department-und").options;			    			
			    			var departmentID = returnNumber(url);
			    			
			    			for(var i=0, n=options.length; i<n; i++)
			    			{
			    				if(options[i].value==departmentID)
			    				{
			    					departmentName = options[i].innerHTML;
			    					document.getElementsByClassName("chosen-single")[0].innerHTML="<span>"+departmentName+"</span><div><b></b></div>"
			    					break;
			    				}
			    			}
		    				
		    			}
		    	});
		    	/**
		    	 * The purpose of the function is to extract the ID of the department from the URL.  Drupal puts the
		    	 * id at the end of the url.  Since the id can vary in digits, this looks to get the ID.  The ID is
		    	 * number.  I use recusion to extract what I need.  The function takes in string containing the URL.
		    	 */
		    	function returnNumber(strURL)
		    	{
		    		var url = strURL;
		    		var end = url.length;
		    		var start = end - 1;
		    		var number 	= url.substring(start,end);//I am getting the last character of the URL
		    		if(!isNaN(number))//checking to see if I do have a number
		    		{
		    			return  returnNumber(url.substring(0,start)) + number;  
		    		}
		    		else//Here I no longer have numbers and return nothing.
		    		{
		    			return "";
		    		}
		    		
		    	}
		    }
	}
  })(jQuery);