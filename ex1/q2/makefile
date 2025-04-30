CC = gcc
CFLAGS = -Wall -std=c99
TARGET = mandelbrot
SRC = mandelbrot.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lm

run: $(TARGET)
	./$(TARGET) -1.627 -0.001

clean:
	rm -f $(TARGET)
