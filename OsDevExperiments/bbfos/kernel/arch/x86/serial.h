#ifndef __SERIAL_H
#define __SERIAL_H

int serial_init();

void serial_puts(char *);
void serial_putc(char);

char serial_getc();

#endif