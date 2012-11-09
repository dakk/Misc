#ifndef UI_WIDGETS_BOX
#define UI_WIDGETS_BOX

#include <types.h>

struct ui_widget_p;

/** \addtogroup ui
 * @{ 
 */

/** \addtogroup ui_box
 * @{
 */

typedef enum { EOT_VERTICAL, EOT_HORIZONTAL } ui_orientation_t;
typedef enum { EBP_START, EBP_END } ui_box_position_t;

/** Box structure */
typedef struct ui_box_p
{
	ui_orientation_t orientation;
} ui_box_t;

/** Create a new label widget */
struct 	ui_widget_p *ui_box_new(ui_orientation_t o);
/** Add a widget */
void	ui_box_add_widget(struct ui_widget_p *w, struct ui_widget_p *nw,
							ui_box_position_t pos);
/** Draw the box */
void	_ui_box_draw(	struct ui_widget_p *w, unsigned x, unsigned y,
							unsigned dx, unsigned dy, unsigned alpha);

/** @} */
/** @} */

#endif
