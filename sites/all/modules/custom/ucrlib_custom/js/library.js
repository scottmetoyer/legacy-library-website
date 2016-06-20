/**
 * 
 */
(function($, Drupal){

  "use strict";

  // Main hours page
  Drupal.behaviors.selectLibrary = {
    attach: function (context, settings) {
    	function get_cookie ( cookie_name )
    	{
    	  var cookie_string = document.cookie ;
    	  if (cookie_string.length != 0)
    	  {
    	    var indexOfItem = cookie_string.indexOf(cookie_name);    	    
    	    var str = cookie_string.substr(indexOfItem);    	    
    	    var indexOfLogOpEqualls = str.indexOf('=')+1;
    	    str = str.substr(indexOfLogOpEqualls);
    	    var indexOfSemiColon = str.indexOf(';');    	    
    	    var cookie_value = str.substr(0,indexOfSemiColon);
    	    return  cookie_value ;
    	  }
    	  return '' ;
    	}
        
      $('.ucrlib-opening-hours-week-block').once('hours-week', function() {
        var row = '.ucrlib-opening-hours-week-block .ucrlib-opening-hours-tab';
        var tab = '.ucrlib-opening-hours-open';
        var week = '.ucrlib-opening-hours-week';
        var container = '.ucrlib-opening-hours-week-container';
        var table = '.ucrlib-opening-hours-table';
        var library = get_cookie("library");
        var innerHTML = "";
        // Remove the link from the library title.
        $(tab + ' .title a').contents().unwrap();
        // Create a space for the table when in "wide" mode.
        $('<div class="ucrlib-opening-hours-table-container" id="ucrlib-opening-hours-table-container" />').appendTo($('#block-ucrlib-custom-hours'));
        
        if(""==library )
        {
            $(row + ':first').addClass('active').find(container).height('auto').find(table).show();
        	$(row + ':first').find(week).clone(true, true).appendTo('#ucrlib-opening-hours-table-container');
      }
        // Switch from row to row.
        $(row + ' ' + tab).click(function() {      
          if ($(this).closest(row).hasClass('active')) {
            return false;
          }          
          // Close currently open row.
          $(row + '.active ' + container).animate({
            height: 0
          }, 250, function() {
            $(this).closest(row).removeClass('active');
          });
          // Fully clone this new row's table for "full width" display
          $('#ucrlib-opening-hours-table-container').empty();//This clears things otherwise, things will keep poping up at the bottom.
          $(this).closest(row).find(week).clone(true, true).show().appendTo('#ucrlib-opening-hours-table-container');//This shows the right hand side
          $(this).closest(row).addClass('active'); //This makes the left hand side selected
          var el = $(this).closest(row).find(container);
          var autoHeight = el.css('height', 'auto').height();
          //Makes things pretty
          el.height(0).animate({
            height: autoHeight
          }, 250, function() {
            $(this).height('auto');
          });
        });
         });
    }
  }
})(jQuery, Drupal);

