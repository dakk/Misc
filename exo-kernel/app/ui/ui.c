#include <libos.h>



void app_ui()
{
	kprintf("UiApp\n");
	device_t *vesa = device_get("vesa");


	ui_env_init();

	ui_env_t *de = ui_get_env();


	/* Panel */
	ui_window_t *panel = ui_window_new("");
	ui_window_set_decorated(panel, 0);
	ui_window_set_position(panel, 0, 0);
	ui_window_set_size(panel, 800, 18);
	ui_add_window(panel);


	ui_window_t *ww = ui_window_new("test");
	ui_window_set_position(ww, 100, 100);
	ui_add_window(ww);


	ui_widget_t *l = ui_label_new("ciaoo");
	ui_window_set_widget(ww, l);


	while(1)
	{
		/* Get mouse and keyboard input */

		/* Pass the events to the widgets */

		/* Render all the environment */
		ui_window_t *w = de->desktops[de->active_desktop].windows;

		unsigned r = 0;
		while(w != NULL)
		{
			_ui_window_draw(w);
			w = w->next;
			kprintf("r%d\n", r);
			r++;
		}

		/* Render the panel */



		/* Swap buffers */
		//render_swap_buffer();
		//
	unsigned i;
	for(i = 0; i < 0xFFFFFF; i++);

		
	}

	for(;;);
}


