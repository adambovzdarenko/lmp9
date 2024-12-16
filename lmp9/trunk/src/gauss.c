#include "gauss.h"

int eliminate(Matrix* mat, Matrix* b) {
    int i, j, k;
    double factor;

    for (k = 0; k < mat->r; k++) {
        if (mat->data[k][k] == 0.0) {
            return 1;
        }

        for (i = k + 1; i < mat->r; i++) {
            factor = mat->data[i][k] / mat->data[k][k];
            for (j = k; j < mat->c; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0;
}
