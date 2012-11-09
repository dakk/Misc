#ifndef UI_WIDGETS_LABEL
#define UI_WIDGETS_LABEL

#include <types.h>

struct ui_widget_p;

/** \addtogroup ui
 * @{ 
 */

/** \addtogroup ui_label
 * @{
 */
#define UI_LABEL_SIZE	512

/** Label structure */
typedef struct ui_label_p
{
	char		text[UI_LABEL_SIZE];	///< Text of the label
	unsigned	size;					///< Size of the text
	uint32_t	color;					///< Color of the text
} ui_label_t;

/** Create a new label widget */
struct 	ui_widget_p *ui_label_new(char *text);
/** Get the text of the label */
char 	*ui_label_get_text(struct ui_widget_p *w);
/** Set the text of the label */
void	ui_label_set_text(struct ui_widget_p *w, char *text);
/** Draw the widget */
void	_ui_label_draw(	struct ui_widget_p *w, unsigned x, unsigned y,
						unsigned dx, unsigned dy, unsigned alpha,
						unsigned *nextx, unsigned *nexty);


/** @} */
/** @} */

#endif
