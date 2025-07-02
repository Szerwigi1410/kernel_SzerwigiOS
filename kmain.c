void kmain(void) {
    const char *message = "Hello, World!";
    char *video_memory = (char *) 0xb8000;

    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i*2] = message[i];
        video_memory[i*2 + 1] = 0x07; // light grey on black
    }

    while (1) {}
}
