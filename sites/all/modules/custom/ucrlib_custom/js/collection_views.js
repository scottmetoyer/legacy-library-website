(function ($) {
  Drupal.behaviors.collection_views = {

		  attach: function(context, settings) {

			  /**
			   * The function below accepts a string of title.  What this function needs
			   * is the title, and based on the title we will know if we want to keep or hide.
			   */
			  function weNeedToHide(title)
			  {
				  var acceptableTitles = [];
				  var size = 0;
				  acceptableTitles[0] = "Eaton Collection of Science Fiction & Fantasy";
				  acceptableTitles[1] =  "Manuscript Collections";
				  acceptableTitles[2] = "Rare Books and Other Special Collections";
				  acceptableTitles[3] = "University Archives";
				  acceptableTitles[4] = "Water Resources Collections & Archives";
				  size = acceptableTitles.length;
				  for(i=0; i<size; i++)
				  {
					  if(acceptableTitles[i]==title)
					  {
						  return false;
					  }					  
				  }
				  return true;
			  }
/**
 * This gets loaded when the web page is loaded.
 */
    	$(window).ready(function() {
    		
			  var intLocation = 0;
			  var title = "";
			  var html2 = "";
			  var i = 1;
			  	//Want to make sure we are on the correct page that we want to manipulate.
				intLocation = document.getElementsByClassName("page-id-libraries-special-collections-university-archives-collections").length;
				if(0 < intLocation )//This makes sure that we are on the page 
				{
					//This is the first row.
					intLocation = document.getElementsByClassName("views-row-1").length;
					//I want to loop until I go through all of the rows.
					while (intLocation>0) 
					{
						title = $( ".views-row-"+i.toString() ).find(".views-field-title").find( ".field-content" ).text();
						if(weNeedToHide(title))//If we need to hide the title, then we do so here.
						{
		             		document.getElementsByClassName("views-total-row-"+i.toString())[0].style.display= "none";		             		
						}
						i++;
						intLocation = document.getElementsByClassName("views-row-"+i.toString()).length;//Checking to see if we have another row.
					}
             		
             		
				}
    	});
    }
}
  
})(jQuery);