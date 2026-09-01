CC = gcc
CFLAGS = -fdiagnostics-color=always -Wall -g
FILES = lf_main.c lf_dev.c lf_dlm.c lf_gf.c
TARGET = lftools

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)

clean:
	rm -f $(TARGET)

.PHONY: all clean