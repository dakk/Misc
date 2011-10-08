#include <libos.h>
#include <string.h>
#include "label.h"


struct ui_widget_p *ui_label_new(char *text)
{
	ui_widget_t *w = (ui_widget_t *) mm_alloc(sizeof(struct ui_widget_p));

	if(w == NULL)
		return w;

	w->type = EWT_LABEL;
	w->wstruct = (void *) mm_alloc(sizeof(struct ui_label_p));
	_strcpy(((ui_label_t *) (w->wstruct))->text, text);
	((ui_label_t *) (w->wstruct))->color = 0;
	((ui_label_t *) (w->wstruct))->size = 16;
	w->draw = _ui_label_draw;
	w->callback = NULL;

	return w;
}


char *ui_label_get_text(struct ui_widget_p *w)
{
	return ((ui_label_t *) (w->wstruct))->text;
}

void ui_label_set_text(struct ui_widget_p *w, char *text)
{
	_strcpy(((ui_label_t *) (w->wstruct))->text, text);
}

void _ui_label_draw(	struct ui_widget_p *w, unsigned x, unsigned y,
						unsigned dx, unsigned dy, unsigned alpha)
{

}

