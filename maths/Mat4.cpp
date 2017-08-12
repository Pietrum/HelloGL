#include "Mat4.h"

Mat4::Mat4() {
    // [ 0 4  8 12 ]
    // [ 1 5  9 13 ]
    // [ 2 6 10 14 ] OpenGL
    // [ 3 7 11 15 ] Standard

    for (float &i : e) i = 0.0f;
}

Mat4 Mat4::identity(float v) {
    Mat4 matrix;

    // [ v 0 0 0 ]
    // [ 0 v 0 0 ]
    // [ 0 0 v 0 ]
    // [ 0 0 0 v ]

    for (int i = 0; i < MAT4_ROWS; i++) {
        matrix.e[i + i * MAT4_COLS] = v;
    }

    return matrix;
}

Mat4& Mat4::multiply(const Mat4& other) {
    // our result
    float result[MAT4_SIZE];

    for (int y = 0; y < MAT4_COLS; y++) {
        for (int x = 0; x < MAT4_ROWS; x++) {
            float sum = 0.0f;
            for (int s = 0; s < MAT4_COLS; s++) {
                sum += e[x + s * MAT4_COLS] * other.e[s + y * MAT4_COLS];
            }
            result[x + y * MAT4_COLS] = sum;
        }
    }

    // override all e elements in one time (after calculation)
    for (int i = 0; i < MAT4_SIZE; i ++) {
        e[i] = result[i];
    }

    return *this;
}