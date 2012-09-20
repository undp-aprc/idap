(function ($) {

  Drupal.behaviors.idap = {
	attach: function (context, settings) {
		
		/* Search Box: Autofill text that clears on click */
		$('#edit-search-text', context).autofill({
			value:'search...',
			defaultTextColor:'#ccc'
		});
		
		/* Main Menu: Control the behaviour of the drop down menus */
		$('#main-menu ul.level-1 li.pillar', context).mouseenter(function() {
			$(this).children('ul').show();
		});
		
		$('#main-menu ul.level-1 li.pillar').mouseleave(function() {
			$(this).children('ul').hide();
		});
		
		/* Manage Block Page Layout */
		
		$('.region-content-blocks .block', context).blockFunctions(); //Add a class to each block, indicating which row it is in, so we can act on each row using equalHeightColumns()
		$('.user-content-blocks .block', context).blockFunctions();
		
		/* Equalise Column Heights */
		setTimeout(function() {
			$('.rowNum-1 .inner-block', context).equalHeightColumns();
			$('.rowNum-2 .inner-block', context).equalHeightColumns();
			$('.user-content-blocks', context).equalHeightColumns();
			$('#footer .theme-block .enclosure', context).equalHeightColumns();
			$('.equal-column-heights', context).equalHeightColumns();
		}, 2000);
		
		/* Hide Page until all elements loaded (do this last) */
		$('body').css('visibility','visible');
		
	}	
}

})(jQuery);