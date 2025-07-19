#include "tty.h"

static char *video_memory = (char *)0xb8000;
static int cursor_pos = 0;  // position in characters (0 to 80*25-1)
#define ROWS 25
#define COLS 80

void tty_putchar(char c) {
    if (c == '\n') {
        // Move cursor to the start of next line
        cursor_pos += COLS - (cursor_pos % COLS);
    } else if (c == '\r') {
        // Move cursor to start of current line
        cursor_pos -= cursor_pos % COLS;
    } else {
        video_memory[cursor_pos * 2] = c;
        video_memory[cursor_pos * 2 + 1] = 0x07; // light grey on black
        cursor_pos++;
    }

    // If we reached end of screen, reset cursor (you can improve with scrolling)
    if (cursor_pos >= ROWS * COLS) {
        cursor_pos = 0;
    }
}

void tty_write(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        tty_putchar(str[i]);
    }
}

void terminal_initialize(void) {
    for (int i = 0; i < ROWS * COLS; i++) {
        video_memory[i * 2] = ' ';
        video_memory[i * 2 + 1] = 0x07;
    }
    cursor_pos = 0;
}
