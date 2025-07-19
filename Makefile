CC = x86_64-elf-gcc
CFLAGS = -ffreestanding -mno-red-zone -Wall -Wextra -nostdlib -nostdinc -fno-builtin -fno-stack-protector -O2
LD = x86_64-elf-ld
LDFLAGS = -T linker.ld

SRC = kmain.c tty.c keyboard.c
OBJ = $(SRC:.c=.o)

all: kernel.elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

kernel.elf: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o kernel.elf

clean:
	del *.o *.elf