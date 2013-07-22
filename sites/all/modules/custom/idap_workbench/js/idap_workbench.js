(function ($) {
  Drupal.behaviors.idap_workbench = {
	attach: function (context, settings) {
		$('.page-thumbnail-container').equalHeightColumns();
		$('.page-thumbnail-container p').equalHeightColumns();
		
		$('.page-thumbnail-container.inactive').bind('mouseenter', function(e) {
			$(this).toggleClass('hover');
		});
		
		$('.page-thumbnail-container.inactive').bind('mouseleave', function(e) {
			$(this).toggleClass('hover');
		});
		
		$('.page-thumbnail-container').bind('click', function(e) {
			$(this).closest('#idap-workbench-form-create-subpage').find('.active').toggleClass('inactive active');
			$(this).closest('#idap-workbench-form-create-landing-page').find('.active').toggleClass('inactive active');
			$(this).toggleClass('inactive active');
			var value = $(this).attr('id');
			$("input[value="+ value +"]").attr('checked',true);
		});
	
		$('#idap-workbench-form-create-subpage .form-type-radios').css('display','none');
		$('#idap-workbench-form-create-landing-page .form-type-radios').css('display','none');
	}	
}

})(jQuery);