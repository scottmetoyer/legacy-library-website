<?php

require_once __DIR__ .'/simplehtmldom.php';
/**
 * The purpose of the class scrapper is to get resources name and href from mainly
 * Scotty, Melvyl, Libguide and the Drupal website which I called thiswebsite.  The class
 * also extract the number of resources found.
 */
class scrapper
{
	private $search;//the item to be searched
	private $htmlPage;//the returned html page in a string
	private $urlPageContents; //This is used for the libguides, this is the link to the webpage
	private $urlNumberOfResults;//This is the number of resources found when give the the $search.
	private $url;//This is the url to be scrapped.
	/**
	 * The function below is the constructor for the class scrapper,
	 * $search -> is the resource to be found
	 * $selector -> is the site that shall be scrapped.
	 */
	public function __construct($search, $selector)
	{
		$this->search = $search;
		$searchEncoded = urlencode($this->search);

		if($selector =="scotty")
		{
			$this->url = "http://scotty.ucr.edu/search/Y?SEARCH=$searchEncoded&searchscope=5";
			$this->htmlPage = file_get_html($this->url);
		}
		elseif($selector =="melvyl")
		{
			$this->url ="http://ucr.worldcat.org/search?submit=1&wclocal_ucr=ai&scope=1&oldscope=1&affiliate=qt&q=$searchEncoded&searchscope=5";
			$this->htmlPage = file_get_html($this->url);
		}
		elseif($selector =="libguide")
		{
			$this->url = "http://guides.lib.ucr.edu/srch.php?q=$searchEncoded";
			$apiUrl = "http://lgapi.libapps.com/1.1/guides?site_id=534&key=97115ae9b0880f4833252d4049715874&sort_by=relevance&search_terms=$searchEncoded";
			$this->htmlPage = file_get_html($apiUrl);
		}
		elseif($selector =="course_reserves_instructor")
		{
			$this->url ="http://scotty.ucr.edu/search/a?searchtype=p&searcharg=$searchEncoded&SORT=D&submit=Search";
			$this->htmlPage = file_get_html($this->url);
		}
		elseif($selector =="course_reserves_course")
		{
			$this->url ="http://scotty.ucr.edu/search/a?searchtype=r&searcharg=$searchEncoded&SORT=D&submit=Search";
			$this->htmlPage = file_get_html($this->url);
		}
	}

	/**
	 * Accessor function to get the url.
	 */
	public function getUrl()
	{
		return $this->url;
	}
	/**
	 * Sets the attribute url
	 * @param string $url
	 */
	public function setDrupalUrl($url)
	{
		$searchEncoded = urlencode($this->search);
		$this->url = $url;
		$completeURL = $this->url .  "/search?search_api_views_fulltext=$searchEncoded";
		$this->htmlPage = file_get_html($completeURL);
	}

	/**
	 *
	 * @param string  $str -> this is the div or element tag that needs to be extracted.
	 * Here I need to get the author.  Returns a string the authors name.
	 */
	private function extractAuthor($str)
	{
		$findStarting = "class=\"author\">";
		$findEnding = "</div>";
		$pos = strpos($str,$findStarting);
		$author = "";
		$tmp = "";
		$strpos = -1;
		if($pos === false)
		{
			$author = "";
		}
		else
		{
			$pos = $pos + 15;
			$tmp = substr($str,$pos);
			$strpos= $strpos * strlen($tmp);
			$pos = strpos($tmp,$findEnding);
			$author = substr($tmp,$strpos,$pos);
		}


		return $author = $author." ";
	}
	/**
	 * The function below adds a comma to the number.
	 * Note, the use of recursion is used to avoid using loops.
	 * $number is a string and returns string
	 */
	public function formatNumber($number)
	{
		$number = trim ( $number  );
		$unformattedNumber = "";
		$formattedNumber ="";
		$length = strlen($number);
		if($length > 3)
		{
			$unformattedNumber = substr($number,0,-3);
			$formattedNumber = ",".substr($number,-3);
			return $this->formatNumber($unformattedNumber).$formattedNumber;
		}
		return $number;
	}

	/**
	 * The function below gets the number of results when Course Reserves is scraped.  Returns a string.
	 */
	public function getCourseReservesNumberOfResults()
	{
		$numb  = 0;
		$pos = 0;
		$end = 0;
		$str = "";

		foreach($this->htmlPage->find('td.browseHeaderData') as $contents)
		{
			$str=(string)$contents;

			if (43!=strlen($str))//this lets me know if its 43 characters long that no results were found
			{
				$pos = strripos($str ,"of")+2;
				$end = strripos($str ,")")-$pos;
				$numb = substr($str ,$pos,$end);
				$numb=$this->formatNumber($numb);
			}
		}
		if(0==$numb)//going to check if one result was found.
		{
			$content = $this->htmlPage->find('td.bibInfoData');
			if(sizeof($content)>0)
			{
				$numb=1;
			}
		}
		return   $numb;
	}

	/**
	 *Gets the contents of the instructor and courses.  The results are in
	 *a 2D array, index 0 = link, index 1 = Title
	 */
	public function getCourseReservesContentsArr()
	{
		$i = 0;
		$size = 0;
		$size = $this->getCourseReservesNumberOfResults();
		$strlink = "";
		$str ="";
		$arr = array();

		if(1==$size)//When there is one item found, the web page displays the entry and not the results.
		{
			$arr[$i][0] = $this->url;
			$arr[$i][1] = $this->search;
		}
		else if($size!=0)
		{
			if($size>5)
			{
				$size=5;
			}

			foreach($this->htmlPage->find('td.browseEntryData') as $elements)
			{
				foreach($elements->find('a') as $link)
				{
					$strlink=$link->href;
					if(strlen($strlink)!=0 && $i < 5)
					{
						$arr[$i][0] = "http://scotty.ucr.edu".$link->href;
						$arr[$i][1] = $link->plaintext;
						$i++;
					}
				}
			}

		}
		return $arr;
	}

	/**
	 * The function below gets the number of results when Scotty is scrapped.  Returns a string.
	 */
	public function getScottyNumberOfResults()
	{
		$totalResultsOfSearch = 0;
		$i = 1;
		$htmlCode = "";
		foreach($this->htmlPage->find('div.browseSearchtoolMessage') as $elements)
		{
			foreach($elements->find('i') as $contents)
			{
				if($i==1)
				{
					$totalResultsOfSearch =  substr($contents,3, strripos($contents,"results found.")-4);
				}
				$i++;
			}
		}
		if(0==$totalResultsOfSearch)
		{
			foreach($this->htmlPage->find('div.bibSearchtoolMessage') as $elements)
			{
				foreach($elements->find('i') as $contents)
				{
					if($i==1)
					{
						$totalResultsOfSearch =  substr($contents,3, strripos($contents,"result found.")-4);
					}
					$i++;
				}
			}

		}
		return $this->formatNumber($totalResultsOfSearch);
	}
	/**
	 * The function below gets the scotty contents.  The contents are returned as a string.
	 * Inside the string, the results are in html format.
	 */
	public function getScottyContents()
	{
		$i = 0;
		$htmlCode = "";
		$title = "";
		$author = "";
	    $rawLink = "";
		foreach($this->htmlPage->find('h2.briefcitTitle') as $elements)
		{
			foreach($elements->find('a') as $link)
			{
				if(trim(strlen($elements->find('a', 0)->plaintext)) > 0 && $i < 5)
				{
					$rawLink = $link->href;
					if(strpos($rawLink,"\\")!=0)
					{
						$htmlCode .=  "<div id=\"scotty_".$i."\"> <a target='_blank' href=\"http://scotty.ucr.edu/$rawLink\">" . $elements->find('a', 0)->plaintext . "</a></div>";
					}
					else
					{
						$htmlCode .=  "<div id=\"scotty_".$i."\"> <a target='_blank' href=\"http://scotty.ucr.edu$rawLink\">" . $elements->find('a', 0)->plaintext . "</a></div>";
					}

					$i++;
				}
			}
		}
		if(""==$htmlCode)
		{
			if('Author'==$this->htmlPage->find('td.bibInfoLabel')[0]->plaintext)
			{
				$author = $htmlCode=$this->htmlPage->find('td.bibInfoData')[0]->plaintext;
				$title = $htmlCode=$this->htmlPage->find('td.bibInfoData')[1]->plaintext;
				$htmlCode ="<div id=\"scotty_0\"> <a target='_blank' href=\"".$this->url."\">" . $title . " " . $author."</a></div>";
			}
			else
			{

				$title = $htmlCode=$this->htmlPage->find('td.bibInfoData')[0]->plaintext;
				$htmlCode ="<div id=\"scotty_0\"> <a target='_blank' href=\"".$this->url."\">" . $title . "</a></div>";
			}
		}

		return $htmlCode;
	}

	/**
	 * The function below gets the number of results when thiswebsite (Drupal) is scrapped.  Returns a string.
	 */
	public function getThiswebsiteNumberOfResults()
	{
		$totalResultsOfSearch = 0;
		$htmlCode ="";
		{
			$i = 1;
			foreach($this->htmlPage->find('div.current-search-item-results') as $elements)
			{
				foreach($elements->find('strong') as $contents)
				{
					if($i==1)
					{
						$totalResultsOfSearch =  $contents;
					}
					$i++;
				}
			}

		}
		return $totalResultsOfSearch;
	}
	/**
	 * The purpose of this function is to eliminate the forward slash
	 * at the end of the hyperlink.  Having this hyperlink causes problems
	 * displaying the hyperlink in the onesearch.
	 *
	 * @param  $str - The hyperlink that needs to be formatted
	 * @return string - returns the string that has been formatted
	 *
	 *
	 */
	private function formatHyperLink($str)
	{
		$size = 0;
		$size = strlen($str)-1;
		$hyperlink = "";
		//echo $str;
		if("/"==$str[$size])
		{
			$hyperlink  = substr($str,0,-1);
		}
		else
		{
			$hyperlink  = $str;
		}
		return $hyperlink;
	}
	/**
	 * The function below gets the thiswebsite (drupal) contents.  The contents are returned as a string.
	 * Inside the string, the results are in html format.
	 */

	public function getThiswebsiteContents()
	{

		$i = 0;
		$htmlCode = "";
		foreach($this->htmlPage->find('h3.title') as $elements)
		{
			foreach($elements->find('a') as $link)
			{
				if(trim(strlen($elements->find('a', 0)->plaintext)) > 0 && $i < 5)
				{
					$strLink = $link->href;
					if(!stristr($strLink,"http"))
					{
						$strLink = $this->url.$link->href;
					}
					$htmlCode .=  "<div id=\"thiswebsite_".$i."\"> <a target='_blank' href=".$this->formatHyperLink($strLink).">" . $elements->find('a', 0)->plaintext . "</a></div>";
					$i++;
				}
			}
		}
		return $htmlCode;
	}

	/**
	 * The function below gets the number of results when Melvylis scrapped.  Returns a string.
	 */
	public function getMelvylNumberOfResults()
	{
		$totalResultsOfSearch = 0;
		$htmlCode ="";
		{
			$i = 1;
			foreach($this->htmlPage->find('div.resultsinfo') as $elements)
			{
				foreach($elements->find('strong') as $contents)
				{
					if($i==2)
					{
						$totalResultsOfSearch =  $contents;
					}
					$i++;
				}
			}

		}
		return $totalResultsOfSearch;
	}

	/**
	 * The function below gets the Melvyl contents.  The contents are returned as a string.
	 * Inside the string, the results are in html format.
	 */
	public function getMelvylContents()
	{
		$i = 0;
		$htmlCode = "";
		$str = "";
		$tmp = "";
		$authorArr = Array(5);

		foreach($this->htmlPage->find('td.result') as $elements)
		{
			if($i<5)
			{
				$authorArr[$i] = $this->extractAuthor($elements);
			}
			$i++;
		}
		$i=0;
		foreach($this->htmlPage->find('div.name') as $elements)
		{
			foreach($elements->find('a') as $link)
			{
				if(trim(strlen($elements->find('a', 0)->plaintext)) > 0 && $i < 5)
				{
					if(strlen($authorArr[$i])==0)
					{
						$htmlCode .=  "<div id=\"melvyl_$i> <a target=\"_blank\" href=\"http://ucr.worldcat.org/$link->href\">" . $elements->find('a', 0)->plaintext . "</a></div>";
					}
					else
					{
						$htmlCode .=  "<div id=\"melvyl_$i\"> <a target=\"_blank\" href=\"http://ucr.worldcat.org/$link->href\">" . $elements->find('a', 0)->plaintext ." ".$authorArr[$i]."</a></div>";
					}

					$i++;
				}
			}
		}

		return $htmlCode;
	}

	/**
	 * The function below gets the LibGuide contents.  The contents are returned as a string.
	 * Inside the string, the results are in html format.
	 */
	public function getLibGuideContents()
	{
		$html = '';
		$i = 0;
		$jsonData = json_decode($this->htmlPage, true);

		foreach($jsonData as $element) {
			$title = $element['name'];
			$url = $element['url'];
			$html .=  '<div id="libguide_'.$i.'"> <a target="_blank" href="'.$url.'">'.$title.'</a></div>';
			$i++;
		}

		return $html;
	}

	/**
	 * The function below gets the number of results when LibGuide is scraped.  Returns a string.
	 */
	public function getLibGuideNumberOfResults()
	{
		$jsonData = json_decode($this->htmlPage, true);
		$count = count($jsonData);
		return $this->formatNumber($count);
	}
}
