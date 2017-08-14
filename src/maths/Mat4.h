#ifndef CLIENT_MAT4_H
#define CLIENT_MAT4_H

#include "Vec4.h"

#define MAT4_ROWS 4
#define MAT4_COLS 4
#define MAT4_SIZE ( MAT4_ROWS * MAT4_COLS )

namespace maths {
    class Mat4 {
    public:
        union {
            float e[MAT4_SIZE];
            Vec4 c[MAT4_COLS];
        };

    public:
        Mat4();

        static Mat4 identity(float);
        static Mat4 orthographic(float, float, float, float, float, float);

        Mat4 &multiply(const Mat4 &);
    };
}

#endif //CLIENT_MAT4_H
