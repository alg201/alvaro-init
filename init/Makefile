CC = gcc

CFLAGS = -Wall -Wextra -Werror -Os
LDFLAGS = -static # need to have all the libraries inside of it.

TARGET = ../initramfs/rootfs/init
SOURCE = src/poweroff/poweroff.c src/main.c 

all:
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o $(TARGET) 

clean:
	rm -f $(TARGET)