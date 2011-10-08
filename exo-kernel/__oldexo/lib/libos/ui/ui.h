#ifndef UI_H
#define UI_H

#include <types.h>
#include "widgets/label.h"
#include "widgets/box.h"
#include "widgets/button.h"


/** \defgroup ui Ui */
/** \defgroup ui_widget UiWidget */
/** \defgroup ui_window UiWindow */
/** \defgroup ui_label UiLabel */
/** \defgroup ui_box UiBox */
/** \defgroup ui_button UiButton */

/** \addtogroup ui
 * @{ */

/** \addtogroup ui_widget
 * @{
 */

#define UI_TITLE_SIZE	128		///< Max size of the window title

/** Widgets */
typedef enum 
{
	EWT_BUTTON,
	EWT_LABEL,
	EWT_BOX,
	EWT_MENU
} ui_widgets_t;

typedef struct ui_widget_p
{
	void 			*wstruct;		///< Struct of the widget
	ui_widgets_t	type;			///< Type of the widget

	void			(*draw)(struct ui_widget_p *w, unsigned x, unsigned y,
							unsigned dx, unsigned dy, unsigned alpha);
	void			(*callback)(struct ui_widget_p *w, void *data);
} ui_widget_t;

/** @} */




/** \addtogroup ui_window
 * @{
 */

/** Window */
typedef struct ui_window_p
{
	unsigned	posx;
	unsigned	posy;
	unsigned	sizex;
	unsigned	sizey;

	bool_t		resizable;
	bool_t		fullscreen;
	bool_t		decorated;
	bool_t		visible;

	bool_t		_render;
	char		title[UI_TITLE_SIZE];
	
	struct ui_widget_p *widget;
	struct ui_window_p *next;
} ui_window_t;

/** Create a new window */
struct ui_window_p *ui_window_new(char *title);
/** Set window title */
void	ui_window_set_title(struct ui_window_p *w, char *title);
/** Get the window title */
char 	*ui_window_get_title(struct ui_window_p *w);
/** Set window fullscreen */
void	ui_window_set_fullscreen(struct ui_window_p *w, bool_t f);
/** Get fullscreen state */
bool_t	ui_window_get_fullscreen(struct ui_window_p *w);
/** Set window size */
void	ui_window_set_size(struct ui_window_p *w, unsigned x, unsigned y);
/** Set window size */
void	ui_window_set_position(struct ui_window_p *w, unsigned x, unsigned y);
/** Set window resizable */
void	ui_window_set_resizable(struct ui_window_p *w, bool_t r);
/** Get window resizable flag */
bool_t	ui_window_get_resizable(struct ui_window_p *w);
/** Set window decorated */
void	ui_window_set_decorated(struct ui_window_p *w, bool_t d);
/** Get if window is decorated */
bool_t	ui_window_get_decorated(struct ui_window_p *w);
/** Add widget */
void	ui_window_set_widget(struct ui_window_p *w, struct ui_widget_p *wid);
/** Get widget */
struct ui_widget_p *ui_window_get_widget(struct ui_window_p *w);
/** Set window visible */
void	ui_window_set_visible(struct ui_window_p *w, bool_t d);
/** Get if window is visible */
bool_t	ui_window_get_visible(struct ui_window_p *w);
/** Draw the window (called by the manager) */
void	_ui_window_draw(struct ui_window_p *w);
/** Called by the app to start the handling loop for a window */
void ui_window_loop(struct ui_window_p *w);

/** @} */



/** Desktop */
typedef struct
{
	struct ui_window_p *active_window;
	struct ui_window_p *windows;
} ui_desktop_t;


/** Gui env */
#define UI_DESK_NUMBER	4

typedef struct 
{
	ui_desktop_t		desktops[UI_DESK_NUMBER];
	unsigned			active_desktop;

} ui_env_t;


void ui_add_window(struct ui_window_p *w);
void ui_del_window(struct ui_window_p *w);
ui_env_t *ui_get_env();
void ui_env_init();

/** @} */


#endif
