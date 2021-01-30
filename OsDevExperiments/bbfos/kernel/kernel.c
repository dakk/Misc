#include "arch/arch.h"

// volatile char *vmem = (volatile char*) 0xB8000;

// void kputs(const char *s) {
//     while(*s != 0) {
//         *vmem++ = *s++;
//         *vmem++ = 0x1e;
//     }
// }

void kmain(void) {
    kdputs("kmain...\n");
    kdputs("kmain...\n");
}