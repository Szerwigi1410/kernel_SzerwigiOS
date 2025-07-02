#include "tty.h"

void kmain(void) {
    tty_write("Hello, Kernel!\n");
    while (1) {}
}
