#include <stdio.h>
#include <complex.h>
#include "mandelbrot.h"

int main() {
    double real, imag;
    printf("Enter a complex number (real and imaginary parts): ");
    scanf("%lf %lf", &real, &imag);

    double complex c = real + imag * I;
    int N = 1000;

    if (is_in_mandelbrot(c, N)) {
        printf("%g + %gi is in the Mandelbrot set\n", real, imag);
    } else {
        printf("%g + %gi is not in the Mandelbrot set\n", real, imag);
    }

    return 0;
}
