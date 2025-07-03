#include "tty.h"
#include "keyboard.h"
#include "idt.h"
#include "isr.h"
#incluse "io.h"

void kmain(void) {
    terminal_initialize() //clears screen if needed
    
    tty_write("Hello, Kernel!\n");
    tty_write("start typing: \n");
    
    init_itd()
    init_keyboard()
    asm volatitle("sti");
    
    while (1) {
        
    
    }
}
