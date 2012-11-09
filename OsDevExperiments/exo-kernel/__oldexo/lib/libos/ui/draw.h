#ifndef UIDRAW_H
#define UIDRAW_H

#include <types.h>

void _uidraw_swap_buffer(unsigned x0, unsigned y0, unsigned x1, unsigned y1);
void _uidraw_clear_buffer(unsigned x0, unsigned y0, unsigned x1, unsigned y1);
void _uidraw_draw_pixel(unsigned x, unsigned y, unsigned cl);
void _uidraw_draw_rect(unsigned x0, unsigned y0, unsigned x1, unsigned y1, unsigned cl, bool_t fill);
void _uidraw_draw_gradient_rect(unsigned x0, unsigned y0, unsigned x1, unsigned y1, unsigned start, unsigned end, bool_t lr);
void _uidraw_draw_text(char *data, unsigned x, unsigned y, unsigned cl);
void _uidraw_draw_line(unsigned x0, unsigned y0, unsigned x1, unsigned y1, unsigned cl);
void _uidraw_draw_buffer(uint32_t *data, unsigned x, unsigned y, unsigned dimx, unsigned dimy);


#endif
