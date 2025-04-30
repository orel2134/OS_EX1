#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>
// מחשב את הערך המוחלט של מספר מרוכב ידנית
double my_abs(double complex z) {
    return sqrt(creal(z) * creal(z) + cimag(z) * cimag(z));
}

int main(int argc, char* argv[]) {
    if (argc < 3 || (argc >= 2 && strcmp(argv[1], "--help") == 0)) {
        fprintf(stderr, "Usage: %s <real_part> <imaginary_part> [max_iterations]\n", argv[0]);
        return 1;
    }
    

    double real = atof(argv[1]);
    double imag = atof(argv[2]);
    int max_iter = (argc >= 4) ? atoi(argv[3]) : 1000;

    double complex c = real + imag * I;
    double complex z = 0 + 0 * I;

    const double M = 2.0;
    int iter = 0;

    while (my_abs(z) <= M && iter < max_iter) {
        z = z * z + c;
        iter++;
    }

    if (my_abs(z) <= M) {
        printf("%g + %gi is in the Mandelbrot set\n", real, imag);
    } else {
        printf("%g + %gi is not in the Mandelbrot set\n", real, imag);
    }

    return 0;
}
