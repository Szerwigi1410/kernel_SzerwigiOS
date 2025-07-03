#include "tty.h"
#include "keyboard.h"
#include "idt.h"
#include "isr.h"
#include "io.h"  

void kmain(void) {
    terminal_initialize();  // clear terminal of needed

    tty_write("Hello, Kernel!\n");
    tty_write("Start typing:\n");

    init_idt();             // 
    init_keyboard();        //
    asm volatile("sti");    // 

    while (1) {
        // loop forever
    }
}