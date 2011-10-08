#include <libos.h>


void main()
{
	ui_env_init();

	ui_env_t *de = ui_get_env();

	while(1)
	{
		/* Get mouse and keyboard input */

		/* Pass the events to the widgets */

		/* Render all the environment */
		ui_window_t *w = de->desktops[de->active_desktop].windows;

		while(w != NULL)
		{
			_ui_window_draw(w);
			w = w->next;
		}

		/* Render the panel */

	}

	for(;;);
}


