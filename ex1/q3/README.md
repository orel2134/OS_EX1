# Mandelbrot Library

This project implements a shared library (`libmandelbrot.so`) that provides a function for checking whether a complex number belongs to the Mandelbrot set.

##  Function API

```c
bool is_in_mandelbrot(double complex c, int N);
```

- **c**: A complex number to test.
- **N**: Maximum number of iterations to test.
- **Returns**: `true` if `c` is in the Mandelbrot set (based on escape time method); `false` otherwise.

The implementation uses `creal()`, `cimag()`, and `sqrt()` to calculate the magnitude of each iteration in the Mandelbrot series:
```c
z₀ = 0  
zₙ₊₁ = zₙ² + c
```

##  Files

| File              | Description                            |
|-------------------|----------------------------------------|
| `mandelbrot.h`    | Function declaration                   |
| `mandelbrot.c`    | Function implementation                |
| `main.c`          | Program to test the function via stdin |
| `libmandelbrot.so`| The compiled shared object (library)   |
| `Makefile`        | Automates compilation and linking      |

##  Build Instructions

To compile everything:

```bash
make
```

To clean:

```bash
make clean
```

## Usage

Run the compiled program:

```bash
./main
```

You’ll be prompted to input a complex number:
```
Enter a complex number (real and imaginary parts): -1.627 -0.001
-1.627 + -0.001i is in the Mandelbrot set
```

##  Examples

```bash
# Example 1
./main
Input: -1.627 -0.001
Output: -1.627 + -0.001i is in the Mandelbrot set

# Example 2
Input: -1.629 -0.001
Output: -1.629 + -0.001i is not in the Mandelbrot set

# Example 3
Input: 0 0
Output: 0 + 0i is in the Mandelbrot set
```
