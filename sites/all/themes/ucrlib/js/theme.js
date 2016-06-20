/*
 * The purpose of this function below is to detect the about->Directory and
 * move the submenu from the right to the left when the size approaches to mobile.  
 * The only reason I am doing this one and not the rest is because the submenu
 * gets lost on the screen.  The submenu would disappear to the right hand of the
 * screen.  This fixes the problem.
 */
(function($, Drupal) {

  "use strict";

  // Image carousel
  Drupal.behaviors.directory = {
    attach: function (context, settings) {
    	function makeTabsGoLeft()
    	{
	    	var $containerWidth = $(window).width();
	    	var index = 0;	    	
	    	var size = document.getElementsByClassName("nav").length;
        	var obj = "";
        	var i = 0;
        	var myFirstTime = true;
        	
        	while (i<size)
        	{	
        		obj = document.getElementsByClassName("nav")[i];
        		if(obj.getElementsByClassName("menu-mlid-1401").length!=0 && 
        				obj.getElementsByTagName("li").length==2 &&
        				document.getElementsByClassName("slicknav_hidden")[i]==undefined &&
        				myFirstTime)
        		{
        			myFirstTime = false;
          			index = i;
           			i=size;        				
        		}
        		i++;
        	}
        	if(index!=0)
        	{
    	    	if($containerWidth<1600)
    	    	{	    		
    		    		document.getElementsByClassName("nav")[index].style.right = "260px";
    		    		document.getElementsByClassName("nav")[index].style.left = "auto";
    		    		document.getElementsByClassName("nav")[index].style.position = "absolute";	        			
    	    	}
    	    	else
    	    	{
    		    		document.getElementsByClassName("nav")[index].style.removeProperty('right');
    		        	document.getElementsByClassName("nav")[index].style.left = "100%";    	    			    			
    	    	}    	               		
        	}
    	}
    	/*
    	 * This function is when the page loads init
    	 */
    	$(window).ready(function(){
    		makeTabsGoLeft();
    	});
    	/*
    	 * This function is when you are on the doc and you make adjustments
    	 */
    	$(document).ready(function(){
    	    $(window).resize(function(){    	    
    	    	makeTabsGoLeft();
    	    });
    	});

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Image carousel
  Drupal.behaviors.borrowingprivileges = {
    attach: function (context, settings) {
    	var intLocation  = 0;
		intLocation = document.getElementsByClassName("page-id-using-the-library-borrowing-privileges").length;
		if(0 < intLocation )
		{
			document.getElementsByClassName("page__content")[0].style.width="100%";
		}
    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Image carousel
  Drupal.behaviors.imageCarousel = {
    attach: function (context, settings) {

      var carousels = [
        '.exhibit__carousel .item-list ul',
        '.page__carousel .item-list ul',
        '.subject-guide__carousel .item-list ul'
      ];

      $(carousels).each(function() {
        $(this).bxSlider({
          captions: true,
          pager: false
        });
      });

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Make boxes same height
  Drupal.behaviors.equalHeightBoxes = {
    attach: function (context, settings) {

      var items = [
        {
          parent: '.front .region-content',
          child: '.front .region-content > .block'
        },
        {
          parent: '.page-id-research-services .region-content',
          child: '.page-id-research-services .region-content > .block'
        }
      ];

      function setHeights() {
        $.each(items, function(idx, el) {
          if ($(el.child).length) {
            $(el.child).height('auto');

            var cWidth = $(el.child).width();
            var pWidth = $(el.parent).width();
            var percent = 100 * cWidth / pWidth;

            if (percent > 45 && percent <= 50) {
              var rows = Math.ceil($(el.child).length / 2);

              for (var i = 0; i < rows; i++) {
                var left = $(el.child).eq((2 * i));
                var right = $(el.child).eq((2 * i) + 1);
                var height = Math.max(left.height(), right.height());

                right.height(height);
                left.height(height);
              }
            }
            else if (percent > 30 && percent <= 35) {
              var rows = Math.ceil($(el.child).length / 3);

              for (var i = 0; i < rows; i++) {
                var left = $(el.child).eq((3 * i));
                var middle = $(el.child).eq((3 * i) + 1);
                var right = $(el.child).eq((3 * i) + 2);
                var height = Math.max(left.height(), middle.height(), right.height());

                right.height(height);
                middle.height(height);
                left.height(height);
              }
            }
          }
        });
      }

      setHeights();
      $(window).load(setHeights);
      $(window).resize(setHeights);

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Show/hide equipment term info on equipment view.
  Drupal.behaviors.equipmentView = {
    attach: function(context, settings) {

      if ($('.view-equipment').length) {

        //
        // Show the taxonomy term
        var tid = parseInt(getUrlParameter('type'), 10);
        if ($.isNumeric(tid)) {
          $('.equipment-term-id-' + tid).show();
        }


        //
        // Collapse the term list to only show the top 5 terms (plus the 'all').
        var isTermsOpen = false;
        $('#edit-type-wrapper').append('<a class="equipment-type-list-toggle" href="#">Show more</a>');

        $('.equipment-type-list-toggle').click(function() {
          if ($(this).hasClass('expanded')) {
            collapseTermList(isTermsOpen);
          }
          else {
            expandTermList(isTermsOpen);
          }
        });

        adjustTermList(isTermsOpen);
        $(window).resize(function() {
          adjustTermList(isTermsOpen);
        });
      }

    }
  };

  function adjustTermList(isTermsOpen) {
    if (!isTermsOpen) {
      collapseTermList();
    }
  }

  function collapseTermList(isTermsOpen) {
    var firstSix = $('#edit-type .form-item').slice(0, 6);
    var firstSixHeight = 0;
    $.each(firstSix, function(idx, el) {
      firstSixHeight += $(el).outerHeight(true);
    });

    $('#edit-type').animate({
        height: firstSixHeight
      }, 250, function() {
        $('.equipment-type-list-toggle').text('Show more').removeClass('expanded');
        isTermsOpen = false;
      }
    );
  }

  function expandTermList(isTermsOpen) {
    var allHeight = 0;
    $.each($('#edit-type .form-item'), function(idx, el) {
      allHeight += $(el).outerHeight(true);
    });

    $('#edit-type').animate({
        height: allHeight
      }, 250, function() {
        $('.equipment-type-list-toggle').text('Show less').addClass('expanded');
        isTermsOpen = true;
      }
    );
  }

  function getUrlParameter(sParam) {
    var sPageURL = window.location.search.substring(1);
    var sURLVariables = sPageURL.split('&');
    for (var i = 0; i < sURLVariables.length; i++) {
      var sParameterName = sURLVariables[i].split('=');
      if (sParameterName[0] == sParam) {
        return sParameterName[1];
      }
    }
  }

})(jQuery, Drupal);


(function($, Drupal) {

  "use strict";

  // Create a mobile nav using the SlickNav library
  Drupal.behaviors.mobileNav = {
    attach: function (context, settings) {

      $('.header__wrapper').once('mobilenav', function() {

        $('.region-hidden .main-nav .menu-block-wrapper > .nav').slicknav({
          prependTo: '.header__wrapper',
          allowParentLinks: true
        });

        // Wait momentarily before adding items to the mobile menu
        function timeout() {
          if ($('.slicknav_nav').length) {
            var search = $('<li class="search-form">')
              .prepend(
                $('#block-views-exp-search-page-page-1').clone()
                  .removeClass('search--header')
                  .addClass('search--mobile-nav')
              );
            $('.slicknav_nav').prepend(search);
            $('.search--mobile-nav').find('.form-text').attr('placeholder', 'Search...');

            var utility = $('<li class="utility-menu">')
              .prepend(
                $('#block-menu-menu-utility').clone()
                  .removeClass('utility-nav--header')
                  .addClass('utility-nav--mobile-nav')
              );
            $('.slicknav_nav').append(utility);
          }
          else {
            setTimeout(function () {
              timeout();
            }, 500);
          }
        }

        timeout();

      });

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Convert labels to placeholders
  Drupal.behaviors.labelToPlaceholder = {
    attach: function (context, settings) {

      var items = [
        {
          wrapper: '.view-database__filters-block #views-exposed-form-databases-page-1',
          label:   '.view-database__filters-block #edit-search-wrapper label',
          input:   '.view-database__filters-block #edit-search'
        }
      ];

      $.each(items, function(idx, el) {
        var text = $(el.label).text();
        $(el.label).hide();
        $(el.input).attr('placeholder', text.trim());
        $(el.wrapper).addClass('placeholderized');
      });

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Simple tabbed content
  Drupal.behaviors.simpleTabs = {
    attach: function (context, settings) {

      var triggers = [
        '.collection__body-tabs-tab a'
      ];
      var wrappers = [
        '.collection__body-tabs'
      ];
      var targets = [
        '.collection__body-tabs-pane'
      ];

      // Initialize the content
      $.each($(triggers), function(idx, val) {
        $(val).addClass('st-trigger').first().addClass('active');
      });
      $.each($(targets), function(idx, val) {
        $(val).addClass('st-target').first().addClass('active');
      });
      $.each($(wrappers), function(idx, val) {
        $(val).addClass('st-wrapper');
      });

      $('a.st-trigger').click(function() {
        var $this = $(this);
        if ($this.hasClass('active')) {
          return false;
        }
        else {
          var id = $this.data('st-trigger');
          var target = '.st-target[data-st-target="' + id + '"]';
          $this.closest('.st-wrapper').find('.st-trigger').removeClass('active');
          $this.closest('.st-wrapper').find('.st-target').removeClass('active');
          $this.addClass('active');
          $this.closest('.st-wrapper').find(target).addClass('active');
        }
        return false;
      });

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Simple tabbed content
  Drupal.behaviors.equalHeightTabs = {
    attach: function (context, settings) {

      function setHeight() {
        var tabHeight = 0;
        $('#quicktabs-collections_subject_areas .quicktabs-tabs li a').each(function(idx, el) {
          $(el).height('auto');
          var $elHeight = $(el).height();
          if ($elHeight > tabHeight) {
            tabHeight = $elHeight;
          }
        });
        $('#quicktabs-collections_subject_areas .quicktabs-tabs li a').height(tabHeight);
      }

      // setHeight();
      // window.onresize = setHeight;

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Convert labels to placeholders
  Drupal.behaviors.tooltips = {
    attach: function (context, settings) {

      var items = [
        '.database__require-logged-in',
        '.database__trial-database',
        '.database__open_access'
      ];

      $.each(items, function(idx, el) {
        if ($(el).length) {
          $(el).tooltip({
            position: {
              my: 'center bottom-20',
              at: 'center top',
              using: function(position, feedback) {
                $(this).css(position);
                $('<div>')
                  .addClass('arrow')
                  .appendTo(this);
              }
            }
          });
        }
      });

    }
  };

})(jQuery, Drupal);
(function($, Drupal) {

	  "use strict";

	  // The purpose of this function is to conform the style to the rest of the site and eliminate the description the 
	  // teaser produces.  This can be found in the /research-services in the database view block.
	  Drupal.behaviors.teaser2 = {
	    attach: function (context, settings) {
	    	
	    	var intLocation = 0;
	    	var size = 0;
	    	intLocation = document.getElementsByClassName("context-research-services").length;
    		if(0 < intLocation )
    		{
    			size = document.getElementsByClassName("database__description").length;
        		for(var i=0; i<size; i++)
        		{
        			document.getElementsByClassName("database__description")[i].style.display= "none";
        			document.getElementsByClassName("database__title")[i].style.fontSize= "15px";
        			document.getElementsByClassName("database__title")[i].style.lineHeight= "1.6";
        		}
    			
    		}

	    	
	    }
	  };

	})(jQuery, Drupal);

(function($, Drupal) {

	  "use strict";
/*
 * The purose of this function is to hide the Instructor title in the events when no instructor has been given.  When the title
 * exists, then the title instructor will show.
 */
	  Drupal.behaviors.eventHideInstructor = {
	    attach: function (context, settings) {
	    	
	    	var intLocation = 0;
	    	var size = 0;
	    	var str = "";
	    	intLocation = document.getElementsByClassName("node-type-event").length;
  		if(0 < intLocation )
  		{
  			size = document.getElementsByClassName("event__instructor").length; 			
      		if(0 == size)
      		{
      			str = document.getElementsByClassName("event__content")[0].innerHTML;
      			document.getElementsByClassName("event__content")[0].innerHTML = str.replace("<h2>Instructors</h2>","");
      		}  			
  		}
	    }
	  };

	})(jQuery, Drupal);
(function($, Drupal) {

	  "use strict";

	  // In page nav for the FAQ page
	  Drupal.behaviors.faqNav = {
	    attach: function (context, settings) {

	      if ($('.view-faqs').length) {
	        var navItems = [];
	        $('.view-faqs > .view-content > h3').each(function(idx, el) {
	          var $el = $(el);
	          var id = $el.text().toLowerCase().replace(/[^\w]/gi, '');
	          $el.attr('id', 'faq-' + id);
	          navItems.push('<a href="#faq-' + id + '" class="in-page">' + $el.text() + '</a>');
	        });

	        if (navItems.length > 0) {
	          var nav = '<div class="faq__in-page-nav"><h3>Jump to:</h3><ul>';
	          $.each(navItems, function(idx, item) {
	            nav += '<li>' + item + '</li>';
	          });
	          nav += '</ul></div>';

	          $('.view-faqs').prepend(nav);
	        }

	        $('a.in-page').on('click', function(event) {
	          var target = $($(this).attr('href'));

	          if (target.length) {
	            event.preventDefault();
	            $('html, body').animate({
	              scrollTop: target.offset().top - 25
	            }, 1000);
	          }
	        });
	      }

	    }
	  };

	})(jQuery, Drupal);

(function($, Drupal) {

	  "use strict";

	  // FAQ accordion
	  Drupal.behaviors.expandCollapseLinks = {
	    attach: function (context, settings) {

	      var ecTriggers = [
	        '.node-faq .faq__title',
	        '.sidebar-first-nav .nav-item--level-2.expanded > .nav-link--level-2'
	      ];
	      var ecWrappers = [
	        '.node-faq',
	        '.sidebar-first-nav .nav-item--level-2.expanded'
	      ];
	      var ecTargets = [
	        '.node-faq .faq__body',
	        '.sidebar-first-nav .nav-item--level-2.expanded > ul.nav'
	      ];

	      // Insert the trigger into the dom
	      $('<a href="#" class="ec-trigger collapsed">Expand</a>').appendTo($(ecTriggers));
	      $.each($(ecWrappers), function(idx, val) {
	        $(val).addClass('ec-wrapper');
	      });
	      $.each($(ecTargets), function(idx, val) {
	        $(val).addClass('ec-target').hide();
	      });

	      // Expand active trail menus
	      $.each($(ecWrappers), function(idxOuter, valOuter) {
	        $.each($(valOuter), function(idxInner, valInner) {
	          if ($(valInner).hasClass('active-trail')) {
	            $(valInner).find('.ec-target').show();
	          }
	        });
	      });

	      $('a.ec-trigger').click(function() {
	        var $this = $(this);
	        if ($this.hasClass('expanded')) {
	          $this.closest('.ec-wrapper').find('.ec-target').slideUp(500, function() {
	            $this.text('Expand').addClass('collapsed').removeClass('expanded');
	          });
	        }
	        else {
	          $this.closest('.ec-wrapper').find('.ec-target').slideDown(500, function() {
	            $this.text('Collapse').addClass('expanded').removeClass('collapsed');
	          });
	        }
	        return false;
	      });

	    }
	  };

	})(jQuery, Drupal);