#include "backsubst.h"

int backsubst(Matrix* x, Matrix* mat, Matrix* b) {
    if (mat->r != mat->c || b->r != mat->r || x->r != mat->r || x->c != 1) {
        return 1;
    }

    for (int i = mat->r - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0.0) {
            return 1;
        }

        x->data[i][0] = b->data[i][0];
        for (int j = i + 1; j < mat->c; j++) {
            x->data[i][0] -= mat->data[i][j] * x->data[j][0];
        }
        x->data[i][0] /= mat->data[i][i];
    }

    return 0;
}
