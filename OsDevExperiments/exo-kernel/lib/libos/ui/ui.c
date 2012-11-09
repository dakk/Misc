#include <libos.h>

ui_env_t ui_global_env;


void ui_env_init()
{
	int i;
	ui_global_env.active_desktop = 0;

	_uidraw_setup();
	
	for(i = 0; i < UI_DESK_NUMBER; i++)
	{
		ui_global_env.desktops[i].active_window = NULL;
		ui_global_env.desktops[i].windows = NULL;
	}
}

ui_env_t *ui_get_env()
{
	return &ui_global_env;
}


void ui_add_window(struct ui_window_p *w)
{
	w->next = ui_global_env.desktops[ui_global_env.active_desktop].windows;
	ui_global_env.desktops[ui_global_env.active_desktop].windows = w;
}


void ui_del_window(struct ui_window_p *w)
{
	int i;
	for(i = 0; i < UI_DESK_NUMBER; i++)
	{
		struct ui_window_p *tmp = ui_global_env.desktops[i].windows;
		struct ui_window_p *prev = NULL;

		while(tmp != NULL)
		{
			if(tmp == w)
			{
				if(prev == NULL)
					ui_global_env.desktops[i].windows = tmp->next;
				else
					prev->next = tmp->next;
				mm_free(w);
				return;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}


