CC=gcc
CFLAG=-Wall

all: ptag

ptag: ptag.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ptag
