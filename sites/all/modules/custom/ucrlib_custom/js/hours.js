(function($) {

  Drupal.behaviors.ucrlibCustomHoursNavigation = {
    attach: function(context, settings) {

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

      var url = 'ucrlib/hours/nojs';
      var oneweek = 60*60*24*7;
      var row = '.ucrlib-opening-hours-week-block .ucrlib-opening-hours-tab';
      var tab = '.ucrlib-opening-hours-open';
      var week = '.ucrlib-opening-hours-week';
      var container = '.ucrlib-opening-hours-week-container';
      var table = '.ucrlib-opening-hours-table';
      var library = get_cookie("library");
      
      $('.ucrlib-opening-hours-week').once('hours', function() {

        var $week = $(this).find('.week');

        $week.prepend('<a href="/' + url + '/' + $(this).data('nid') + '/' + ($(this).data('date') - oneweek) + '" class="use-ajax prev">' + Drupal.t('prev') + '</a>');
        $week.append('<a href="/' + url + '/' + $(this).data('nid') + '/' + ($(this).data('date') + oneweek) + '" class="use-ajax next">' + Drupal.t('next') + '</a>');

        
        Drupal.attachBehaviors($week, settings);
        
        if("science"==library)
        {
        	$('#ucrlib-opening-hours-table-container').empty();                     
            $(row +":eq(1)").addClass('active').find(container).height('auto').find(table).show();//This highlights the left hand side of the table where the library names are displayed.
            $(row +":eq(1)").find(week).clone(true, true).appendTo('#ucrlib-opening-hours-table-container');//This shows the right hand side of the table where all the library hours are.
        }
        else if("multimedia"==library)
        {
        	$('#ucrlib-opening-hours-table-container').empty();
        	$(row +":eq(2)").addClass('active').find(container).height('auto').find(table).show();//This highlights the left hand side of the table where the library names are displayed.
        	$(row +":eq(2)").find(week).clone(true, true).appendTo('#ucrlib-opening-hours-table-container');//This shows the right hand side of the table where all the library hours are.
        }
        else if("music"==library)
        {
        	$('#ucrlib-opening-hours-table-container').empty();
        	$(row +":eq(3)").addClass('active').find(container).height('auto').find(table).show();//This highlights the left hand side of the table where the library names are displayed.
        	$(row +":eq(3)").find(week).clone(true, true).appendTo('#ucrlib-opening-hours-table-container');//This shows the right hand side of the table where all the library hours are.
        }
        else if("collections"==library)
        {
        	$('#ucrlib-opening-hours-table-container').empty();
        	$(row +":eq(4)").addClass('active').find(container).height('auto').find(table).show();//This highlights the left hand side of the table where the library names are displayed.
        	$(row +":eq(4)").find(week).clone(true, true).appendTo('#ucrlib-opening-hours-table-container');//This shows the right hand side of the table where all the library hours are.        	        	      	
        }
        else if("rivera"==library)
        {
        	$('#ucrlib-opening-hours-table-container').empty();
        	$(row +":eq(0)").addClass('active').find(container).height('auto').find(table).show();//This highlights the left hand side of the table where the library names are displayed.
        	$(row +":eq(0)").find(week).clone(true, true).appendTo('#ucrlib-opening-hours-table-container');//This shows the right hand side of the table where all the library hours are.        	        	      	
        }

      });

    }
  };

})(jQuery);
