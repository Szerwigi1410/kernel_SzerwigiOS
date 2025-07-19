#ifndef TTY_H
#define TTY_H

// Prints a single character to the screen
void tty_putchar(char c);

// Prints a null-terminated string to the screen
void tty_write(const char* str);

void terminal_initialize(void);

#endif // TTY_H
