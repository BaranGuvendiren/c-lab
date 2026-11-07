CC = gcc
CFLAGS = -I include

all:
	$(CC) src/main.c src/shell.c $(CFLAGS) -o build/c-lab

clean:
	rm -f c-lab