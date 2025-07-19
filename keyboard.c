#include "keyboard.h"
#include "io.h"
#include "tty.h"

unsigned char keymap[128] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0, '\\',
    'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ',
    0,  // F1
    // (I or you will fill in more keys later)
};

void keyboard_handler() {
    unsigned char scancode = inb(0x60);

    // Check if it's a key press (ignore key release for now)
    if (scancode < 128) {
        char ch = keymap[scancode];
        if (ch) {
            tty_putchar(ch);
        }
    }
}

void init_keyboard() {
    // IRQ1 = keyboard = interrupt 33 (0x21)
    //someone will hook this in your IDT setup, or call from kmain
}