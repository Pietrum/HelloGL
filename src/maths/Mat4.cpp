#include "Mat4.h"

namespace maths {
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

    Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
        Mat4 matrix = identity(1.0f);

        // [ 2 / (r - l) |      0      |       0      | - (r + l) / (r - l) ]
        // [     0       | 2 / (t - b) |       0      | - (t + b) / (t - b) ]
        // [     0       |      0      | -2 / (f - n) | - (f + n) / (f - n) ]
        // [     0       |      0      |       0      |          1          ]

        matrix.c[0].x = 2.0f / (right - left);
        matrix.c[1].y = 2.0f / (top - bottom);
        matrix.c[2].z = -2.0f / (far - near);
        matrix.c[3].x = -1.0f * (right + left) / (right - left);
        matrix.c[3].y = -1.0f * (top + bottom) / (top - bottom);
        matrix.c[3].z = -1.0f * (far + near) / (far - near);

        return matrix;
    }

    Mat4 &Mat4::multiply(const Mat4 &other) {
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
        for (int i = 0; i < MAT4_SIZE; i++) {
            e[i] = result[i];
        }

        return *this;
    }
}
