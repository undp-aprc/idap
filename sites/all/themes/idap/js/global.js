(function ($) {

  Drupal.behaviors.idap = {
	attach: function (context, settings) {
		
		/* Preload images */
		$(['/sites/all/themes/idap/images/indicator-arrow.png','/sites/all/themes/idap/images/ul-bullet-large.png']).preload();
		
		/* Search Box: Autofill text that clears on click */
		$('#edit-search-text', context).autofill({
			value:'search...',
			defaultTextColor:'#ccc'
		});
		
		/* Main Menu: Control the behaviour of the drop down menus */
		$('.level-1-li').bind('click',function(e) {
			$(e.target).closest('.level-1-li').addClass('selected');
			$(e.target).closest('.items').find('.level-1-li').each(function() {
				if(!$(this).hasClass('selected') || $(this).find('.level-2').css('display') == 'block') {
					$(this).find('.level-2').css('display','none');
					$(this).find('.has-background').css('display','none');
				} else {
					$(this).find('.level-2').slideToggle();
					$(this).find('.has-background').slideToggle();
				}
			});
			$(e.target).closest('.level-1-li').removeClass('selected');
		});
		
		/* Manage Block Page Layout */
		
		//$('.region-content-blocks .block', context).blockFunctions(); //Add a class to each block, indicating which row it is in, so we can act on each row using equalHeightColumns()
		//$('.user-content-blocks .block', context).blockFunctions();
		
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