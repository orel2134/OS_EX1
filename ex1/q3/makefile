CC = gcc
CFLAGS = -Wall -std=c99 -fPIC
LDFLAGS = -shared
TARGET = main
LIB = libmandelbrot.so

all: $(TARGET)

#Step 1: Compiling the library
$(LIB): mandelbrot.o
	$(CC) $(LDFLAGS) -o $(LIB) mandelbrot.o

mandelbrot.o: mandelbrot.c mandelbrot.h
	$(CC) $(CFLAGS) -c mandelbrot.c

# Step 2: Compile main with the library
$(TARGET): main.o $(LIB)
	$(CC) -o $(TARGET) main.o -L. -lmandelbrot -lm

main.o: main.c mandelbrot.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o *.so $(TARGET)
