#include <libos.h>
#include <string.h>
#include "draw.h"


extern ui_env_t ui_global_env;

struct ui_window_p *ui_window_new(char *title)
{
	struct ui_window_p *w = (ui_window_t *) mm_alloc(sizeof(ui_window_t));

	if(w == NULL)
		return w;

	_strcpy(w->title, title);
	w->posx = w->posy = 10;
	w->sizex = w->sizey = 120;
	w->resizable = true;
	w->fullscreen = false;
	w->visible = true;
	w->decorated = true;
	w->_render = false;

	return w;
}


void ui_window_set_title(struct ui_window_p *w, char *title)
{
	_strcpy(w->title, title);
}


char *ui_window_get_title(struct ui_window_p *w)
{
	return w->title;
}


void ui_window_set_fullscreen(struct ui_window_p *w, bool_t f)
{
	w->fullscreen = f;
}


bool_t ui_window_get_fullscreen(struct ui_window_p *w)
{
	return w->fullscreen;
}


void ui_window_set_size(struct ui_window_p *w, unsigned x, unsigned y)
{
	w->sizex = x;
	w->sizey = y;
}


void ui_window_set_position(struct ui_window_p *w, unsigned x, unsigned y)
{
	w->posx = x;
	w->posy = y;
}


void ui_window_set_resizable(struct ui_window_p *w, bool_t r)
{
	w->resizable = r;
}


bool_t ui_window_get_resizable(struct ui_window_p *w)
{
	return w->resizable;
}


void ui_window_set_decorated(struct ui_window_p *w, bool_t d)
{
	w->decorated = d;
}

bool_t ui_window_get_decorated(struct ui_window_p *w)
{
	return w->decorated;
}


void ui_window_set_widget(struct ui_window_p *w, struct ui_widget_p *wid)
{
	w->widget = wid;
}


void ui_window_set_menu(struct ui_window_p *w, struct ui_widget_p *menu)
{
	w->menu = wid;
}



struct ui_widget_p *ui_window_get_widget(struct ui_window_p *w)
{
	return w->widget;
}


void ui_window_set_visible(struct ui_window_p *w, bool_t d)
{
	w->visible = d;
}


bool_t ui_window_get_visible(struct ui_window_p *w)
{
	return w->visible;
}


void _ui_window_draw(struct ui_window_p *w)
{
	if(w->decorated)
	{
		_uidraw_draw_rect_fill(w->posx - 1, w->posy - 15, w->posx + w->sizex + 1, w->posy, 
						0x555555);
		_uidraw_draw_rect(w->posx - 1, w->posy - 15, w->sizex + w->posx + 1, 
						w->sizey + w->posy + 1, 0x111111);

		_uidraw_draw_line(w->posx, w->posy - 1, w->sizex + w->posx, w->posy - 1, 0x111111);	
		_uidraw_draw_line(w->posx + w->sizex - 15, w->posy - 15, w->sizex + w->posx - 15, w->posy, 0x111111);
						
		_uidraw_draw_letter(16, 'x', w->posx + w->sizex - 10, w->posy - 13, 0xFFFFFF);
		_uidraw_draw_text(16, w->title, w->posx + 10, w->posy - 12, 0xFFFFFF);
	}
	
	_uidraw_draw_rect_fill(w->posx, w->posy, w->posx + w->sizex, w->posy + w->sizey, 0xA0A0A0);

	unsigned i, j;

	if(w->menu != NULL);
	w->widget->draw(w->widget, w->posx + 1, w->posy + 1, w->posx + w->sizex - 1, w->posy + w->sizey - 1, 255, &i, &j);
}



void ui_window_loop(struct ui_window_p *w)
{
	w->_render = true;
	while(1);
}



