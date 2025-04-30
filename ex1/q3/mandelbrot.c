#include "mandelbrot.h"
#include <math.h>

double my_abs(complex double z) {
    return sqrt(creal(z) * creal(z) + cimag(z) * cimag(z));
}

bool is_in_mandelbrot(complex double c, int N) {
    complex double z = 0;
    for (int i = 0; i < N; ++i) {
        if (my_abs(z) > 2.0)
            return false;
        z = z*z + c;
    }
    return true;
}
