
#ifndef SCREENPIG_RENDER_H
#define SCREENPIG_RENDER_H

#include <types.h>


void _uidraw_swap_buffer();
void _uidraw_draw_pixel(uint32_t, uint32_t, uint32_t);
uint32_t _uidraw_get_pixel(uint32_t, uint32_t);
void _uidraw_draw_text(uint8_t, char *, uint32_t, uint32_t, uint32_t);
void _uidraw_draw_letter(uint8_t, char, uint32_t, uint32_t, uint32_t);
void _uidraw_draw_rect(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
void _uidraw_draw_rect_fill(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
void _uidraw_draw_rect_fill_gradient(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
void _uidraw_draw_rect_bordered(uint32_t, uint32_t, uint32_t, uint32_t, uint8_t, uint32_t, uint32_t);
void _uidraw_draw_rect_bordered_gradient(uint32_t, uint32_t, uint32_t, uint32_t, uint8_t, uint32_t, uint32_t, uint32_t);
void _uidraw_draw_line(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
void _uidraw_draw_bitmap(uint32_t *, uint32_t, uint32_t, uint32_t, uint32_t);
void _uidraw_setup();

#endif
