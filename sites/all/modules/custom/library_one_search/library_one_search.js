(function ($) {
    Drupal.behaviors.library_one_search = {

        attach: function (context, settings) {
            /*
             * This is the where all the magic occurs for searching.
             * 
             */

            function getUrl() {
                return window.location.protocol + "//" + window.location.host + settings.basePath;
            }

            function search() {
                $(".slicknav_open").click();

                var text = document.querySelectorAll('#edit-search-api-views-fulltext'); //This is the shadow DOM
                var size = text.length;
                var search = "";
                var url = "";

                // At this point, all the textboxes will have the same search query, so thefore I will get from the very first one.
                search = text[0].value;

                //Checking to see if the enduser has put something in the search.
                if ("" != search && null != search) {
                    url = getUrl();

                    //There are four call backs because I am scraping Melvyl, Scotty, Libapps & the drupal site.
                    var requestCallback = new MyRequestsCompleted({
                        numRequest: 6
                    });
                    //This ajax below scrapes the course reserves which is still part of scotty
                    $.ajax({
                        url: url + '/onesearch/get/course_reserves/' + search,
                        success: function (data) {
                            //Sets the headers
                            setColumnLinks(data, "coursereserves");
                            //setColumnDisable("coursereserves");
                        },
                        error: function (request, status, error) {
                            setColumnError("coursereserves");
                        }
                    });

                    //This ajax below scrapes the scotty website
                    $.ajax({
                        url: url + '/onesearch/get/scotty/' + search,
                        success: function (data) {
                            //Sets the headers
                            setColumnLinks(data, "scotty");
                        },
                        error: function (request, status, error) {
                            setColumnError("scotty");
                        }
                    });
                    //This ajax below scrapes the libguide website
                    $.ajax({

                        url: url + '/onesearch/get/libguide/' + search,
                        success: function (data) {
                            //Sets the headers
                            setColumnLinks(data, "libguide");
                        },
                        error: function (request, status, error) {
                            setColumnError("libguide");
                        }
                    });
                    //This ajax below scrapes the melvyl website
                    $.ajax({
                        url: url + '/onesearch/get/melvyl/' + search,
                        success: function (data) {
                            setColumnLinks(data, "melvyl");

                        },
                        error: function (request, status, error) {
                            setColumnError("melvyl");
                        }

                    });
                    //This ajax below scrapes the drupal site
                    $.ajax({
                        url: url + '/onesearch/get/thiswebsite/' + search,
                        success: function (data) {
                            //Sets the headers
                            setColumnLinks(data, "thiswebsite");
                        },
                        error: function (request, status, error) {
                            setColumnError("thiswebsite");

                        }
                    });

                    //This ajax below scrapes the melvyl website
                    $.ajax({
                        url: url + '/onesearch/get/calisphere/' + search,

                        success: function (data) {
                            //Sets the headers
                            setColumnLinks(data, "calisphere");
                        },
                        error: function (request, status, error) {
                            setColumnError("calisphere");
                        }
                    });

                }
                    //	This tells the enduser that they've entered a blank search.
                else if ("" == search && null != search) {
                    document.getElementById("emptysearch").style.display = "";
                }

            }
            /*
             * The function below sets the column and error message when an error message occurs with the ajax call.
             * resource -> is a string and the name of the resource
             */
            function setColumnError(resource) {
                document.getElementById(resource + '_progress').style.display = 'none';
                document.getElementById(resource + '_problem').style.display = '';
                document.getElementById(resource + '_totalresults').style.display = 'none';
            }

            function setColumnDisable(resource) {
                document.getElementById(resource + '_progress').style.display = 'none';
                document.getElementById(resource + '_disabled').style.display = '';
                document.getElementById(resource + '_totalresults').style.display = 'none';
            }

            /**
             * The purpose of the function below is to set the header for the resource that's being passed.  
             * The data is the page returned from the ajax call.  The resource is what is being passed, ex:
             * scotty, melvyl libguides
             */
            function setColumnLinks(data, resource) {
                var intNumbOfResults = 0;
                var $myDiv = "";
                var htmlCode = "";
                var title = "";
                var str = "";
                var href = "";
                var myDivResource = "";
                var title = ""; // Header title.
                var url = "";
                var numberOfResults = $(data).find('#numberOfResults').text();
                intNumbOfResults = parseInt(numberOfResults.replace(",", ""));

                if (0 == intNumbOfResults && "coursereserves" != resource) {
                    document.getElementById(resource + '_progress').style.display = 'none';
                    document.getElementById(resource + '_no-results').style.display = '';
                    myDivResource = resource + '_totalresults';
                    url = $(data).find('#url').text();
                    title = ' <a href="' + url + '" target="_blank" > SEE ALL  ' + numberOfResults + ' RESULTS</a>';
                    document.getElementById(myDivResource).innerHTML = title;

                }
                else if (isNaN(intNumbOfResults) && "coursereserves" != resource) {
                    document.getElementById(resource + '_progress').style.display = 'none';
                    document.getElementById(resource + '_problem').style.display = '';
                }
                else {
                    if ("coursereserves" != resource) {
                        myDivResource = resource + '_totalresults';
                        url = $(data).find('#url').text();

                        title = ' <a href="' + url + '" target="_blank" > SEE ALL  ' + numberOfResults + ' RESULTS</a>';
                        document.getElementById(myDivResource).innerHTML = title;

                        //I want to limit the results of no more than 5.
                        if (intNumbOfResults > 5) {
                            intNumbOfResults = 5;
                        }

                        htmlCode = htmlCode + "<div id='results'>";
                        //Below is where I extract the the title and href from the data variable and put 
                        //the info on to the main web page.
                        for (var i = 0; i < intNumbOfResults; i++) {
                            htmlCode = htmlCode + '<div class=\'\' id="' + resource + i + '">';
                            $myDiv = $(data).find('#' + resource + '_' + i);
                            str = $myDiv.find('a').attr("href");
                            href = str.replace("\\", "/"); //For whatever reason, if I didn't do this the hyper link wouldn't work in firfox
                            title = $myDiv.find('a').text();
                            htmlCode = htmlCode + '<ul><li><a class="ellipsis" target="_blank" href="' + href + '">' + title + '</a></li></ul>';
                            htmlCode = htmlCode + '</div>';
                        }
                        htmlCode = htmlCode + '</div>';
                        document.getElementById(resource + '_progress').style.display = 'none';
                        document.getElementById(resource + '_results').style.display = '';
                        document.getElementById(resource + "_results").innerHTML = htmlCode;

                    }
                    else {
                        document.getElementById('coursereserves_totalresults').style.display = 'none';
                        numberOfResults = $(data).find('#numberOfResultsCourse').text();
                        intNumbOfResults = parseInt(numberOfResults.replace(",", ""));

                        if (intNumbOfResults > 5) {
                            intNumbOfResults = 5;
                        }

                        var i = 0;
                        url = $(data).find('#urlCourse').text();
                        title = ' <a href="' + url + '" target="_blank" > SEE ALL  ' + numberOfResults + '</a>';
                        document.getElementById("coursereservescourse_totalresults").innerHTML = title;

                        if (intNumbOfResults > 0) {

                            htmlCode = htmlCode + "<div id='results'>";
                            for (i = 0; i < intNumbOfResults; i++) {
                                $myDiv = $(data).find('#coursereservescourse_' + i);
                                str = $myDiv.find('a').attr("href");
                                href = str.replace("\\", "/"); //For whatever reason, if I didn't do this the hyper link wouldn't work in firfox

                                title = $myDiv.find('a').text();

                                htmlCode = htmlCode + '<div class=\'\' id="coursereservescourse' + i + '">';
                                htmlCode = htmlCode + '<ul><li><a class="ellipsis" target="_blank" href="' + href + '">' + title + '</a></li></ul>';
                                htmlCode = htmlCode + '</div>';
                            }
                            htmlCode = htmlCode + '</div>';
                            document.getElementById('coursereservescourse_progress').style.display = 'none';
                            document.getElementById('coursereservescourse_results').style.display = '';
                            document.getElementById("coursereservescourse_results").innerHTML = htmlCode;

                            htmlCode = "<div id='results'>";

                        }
                        else {
                            document.getElementById('coursereservescourse_progress').style.display = 'none';
                            document.getElementById('coursereservescourse_no-results').style.display = '';
                        }
                        url = $(data).find('#urlInstructor').text();
                        numberOfResults = $(data).find('#numberOfResultsInstructor').text();
                        intNumbOfResults = parseInt(numberOfResults.replace(",", ""));

                        title = ' <a href="' + url + '" target="_blank" > SEE ALL  ' + numberOfResults + '</a>';
                        document.getElementById("coursereservesinstructor_totalresults").innerHTML = title;

                        if (intNumbOfResults > 5) {
                            intNumbOfResults = 5;
                        }

                        if (intNumbOfResults > 0) {
                            for (i = 0; i < intNumbOfResults; i++) {
                                $myDiv = $(data).find('#coursereservesinstructor_' + i);
                                str = $myDiv.find('a').attr("href");
                                href = str.replace("\\", "/"); //For whatever reason, if I didn't do this the hyper link wouldn't work in firfox
                                title = $myDiv.find('a').text();
                                htmlCode = htmlCode + '<div class=\'\' id=instructor"' + i + '">';
                                htmlCode = htmlCode + '<ul><li><a class="ellipsis" target="_blank" href="' + href + '">' + title + '</a></li></ul>';
                                htmlCode = htmlCode + '</div>';
                            }
                            htmlCode = htmlCode + '</div>';
                            document.getElementById('coursereservesinstructor_progress').style.display = 'none';
                            document.getElementById('coursereservesinstructor_results').style.display = '';
                            document.getElementById("coursereservesinstructor_results").innerHTML = htmlCode;
                        }
                        else {
                            document.getElementById('coursereservesinstructor_progress').style.display = 'none';
                            document.getElementById('coursereservesinstructor_no-results').style.display = '';
                        }
                    }
                }

            }

            /**
             * The purpose of the function below is to tell me where I am at in the site based on the page.
             */
            function hereIsThePage() {
                var intLocation = 0; //page-onesearch
                intLocation = document.getElementsByClassName("section-home").length;

                if (0 < intLocation) {
                    return "home";
                }

                intLocation = document.getElementsByClassName("section-search").length;
                if (0 < intLocation) {
                    return "search";
                }

                intLocation = document.getElementsByClassName("page-onesearch").length;
                if (0 < intLocation) {
                    return "onesearch";
                }

                return "";
            }

            /**
             * The purpose of this function is to force all three search boxes the same value.  Since there is up to three textboxes
             * If I notice if one is different from the other two, then I know which one has been changed and know
             * what to put in all three boxes.  
             */
            function makeAllTextBoxTheSame(myNewValue) {

                var text = document.querySelectorAll('#edit-search-api-views-fulltext'); //This is the shadow DOM
                //Here I have three text boxes
                if (3 == text.length) {
                    text[1].value = myNewValue;
                    text[2].value = myNewValue;
                    text[0].value = myNewValue;
                }
                else if (2 == text.length)//Here I have two text boxes
                {
                    text[1].value = myNewValue;
                    text[0].value = myNewValue;
                }
            }

            /**
             * I had to change the type from submit to button so that I can impose 
             * my javascript onto the form.
             */
            function convertToButton() {
                $("input[id='edit-submit-search-page']").prop("type", "button");
            }

            function notInOneSearchGet() {
                var total = 0;
                var results = true;
                total = total + document.getElementsByClassName("page-onesearch-get-libguide").length;
                total = total + document.getElementsByClassName("page-onesearch-get-calisphere").length;
                total = total + document.getElementsByClassName("page-onesearch-get-course-reserves").length;
                total = total + document.getElementsByClassName("page-onesearch-get-scotty").length;
                total = total + document.getElementsByClassName("page-onesearch-get-melvyl").length;
                total = total + document.getElementsByClassName("page-onesearch-get-thiswebsite").length;

                if (total > 0) {
                    results = false;

                }

                return results;
            }

            /**
             * This gets loaded when the web page is loaded.
             */
            $(window).ready(function () {

                var iAmOnThisPage = hereIsThePage();
                var innerHTML = "";

                //The code below adds the tags that are conducive to the onesearch.
                if ("search" != iAmOnThisPage) {
                    if ("onesearch" === iAmOnThisPage) {
                        innerHTML = "<span class=\"breadcrumb__link\"><a href=\"/\">Home</a></span>" +
                        "<span class=\"breadcrumb__separator\"> / </span>" +
                        "<span class=\"breadcrumb__page-title\">search</span>";

                        document.getElementsByClassName("breadcrumb")[0].innerHTML = innerHTML;
                    }

                    convertToButton();

                    if (0 == document.getElementsByClassName("emptysearch").length) {
                        makeAllTextBoxTheSame(decodeURI(parseURLReturnSearch(getUrl() + location.pathname)));
                    }
                }
                else {
                    var button = document.querySelectorAll('#edit-submit-search-page'); //This is the shadow DOM
                    button[0].setAttribute("type", "button");
                    button[1].setAttribute("type", "button");
                    document.getElementsByClassName("form-text")[2].setAttribute("id", "search-page");
                }

                intLocation = document.getElementsByClassName("page-onesearch").length;

                if (0 < intLocation && notInOneSearchGet()) {
                    search();
                }

            });

            function parseURLReturnSearch(url) {
                var start = 0;
                var length = 0;
                var search = "";
                start = url.lastIndexOf("/") + 1;
                length = url.length - start;

                var n = url.indexOf("onesearch");
                if (n > 0) {
                    search = url.substr(start, length);
                }

                return search;
            }

            /**
             * This is when they hit enter
             */
            $(document).keypress(function (e) {
                var iAmOnThisPage = hereIsThePage();
                var divs = $("div");
                var curIdx = divs.index(this);

                if (13 == e.which && "edit-search-api-views-fulltext" == e.target.id &&
                        !("search" == iAmOnThisPage && 2 == curIdx)) //This is when the user hits enter and is in the textarea. 
                {

                    /*
                     * The logic below is to force only on certain pages for the one search.  If the enduser is somewhere else,
                     * then the enter works as it should.  
                     */
                    makeAllTextBoxTheSame(e.target.value);
                    window.location = getUrl() + "onesearch/" + encodeURI(e.target.value);
                    return false;
                }
            });

            /**
             * The purpose of this function is if the enduser changes a value in one of three text boxes that
             * we make sure that the latest change is captured.
             */
            $(".form-text").blur(function ()//id="edit-search-api-views-fulltext" 
            {
                var theIDIamIn = this.id;
                var iAmOnThisPage = hereIsThePage();
                var divs = $(".form-text");
                var curIdx = divs.index($(this));

                if ("edit-search-api-views-fulltext" == theIDIamIn &&
                        !("search" == iAmOnThisPage && 2 == curIdx)) {
                    makeAllTextBoxTheSame(this.value);
                }
            });

            /**
             * This function is when they click on the search button.  This forces the one-search when applicable.
             */
            $(".form-submit").click(function () {
                /*
                 * The logic below is to make certain that I am in the main page where the one search is done.  If I am in the main page
                 * then use the search, otherwise continue using whatever funtionality has already been established.
                 */
                var whatIamClicking = this.id;
                var iAmOnThisPage = hereIsThePage();
                var divs = $(".form-submit");
                var curIdx = divs.index($(this));

                if ("edit-submit-search-page" == whatIamClicking &&
                        !("search" == iAmOnThisPage && 2 == curIdx)) {
                    var text = document.querySelectorAll('#edit-search-api-views-fulltext'); //This is the shadow DOM
                    var url = getUrl();

                    if (text[0].value != null || text[0].value != "") {
                        window.location.href = url + "onesearch/" + encodeURI(text[0].value);
                    }
                    else {
                        window.location = url + "onesearch/";
                    }
                }
            });

            var MyRequestsCompleted = (function () {
                var numRequestToComplete,
                    requestsCompleted,
                    callBacks,
                    singleCallBack;

                return function (options) {
                    if (!options) options = {};

                    numRequestToComplete = options.numRequest || 0;
                    requestsCompleted = options.requestsCompleted || 0;
                    callBacks = [];
                    var fireCallbacks = function () {
                        for (var i = 0; i < callBacks.length; i++) callBacks[i]();
                    };
                    if (options.singleCallback) callBacks.push(options.singleCallback);
                    this.addCallbackToQueue = function (isComplete, callback) {
                        if (isComplete) requestsCompleted++;
                        if (callback) callBacks.push(callback);
                        if (requestsCompleted == numRequestToComplete) fireCallbacks();
                    };
                    this.requestComplete = function (isComplete) {
                        if (isComplete) requestsCompleted++;
                        if (requestsCompleted == numRequestToComplete) fireCallbacks();
                    };
                    this.setCallback = function (callback) {
                        callBacks.push(callBack);
                    };
                };
            })();
        }
    }
})(jQuery);