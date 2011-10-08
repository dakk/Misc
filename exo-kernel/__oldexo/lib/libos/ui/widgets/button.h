#ifndef UI_WIDGETS_BUTTON
#define UI_WIDGETS_BUTTON

#include <types.h>

struct ui_widget_p;

/** \addtogroup ui
 * @{ 
 */

/** \addtogroup ui_button
 * @{
 */

#define UI_BUTTON_LABEL_SIZE	512

/** Button structure */
typedef struct ui_button_p
{
	char		text[UI_BUTTON_LABEL_SIZE];
} ui_button_t;

/** Create a new button widget */
struct 	ui_widget_p *ui_button_new(char *text);
/** Draw the button */
void	_ui_button_draw(	struct ui_widget_p *w, unsigned x, unsigned y,
							unsigned dx, unsigned dy, unsigned alpha);


/** @} */
/** @} */

#endif
