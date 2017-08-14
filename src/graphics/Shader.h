#ifndef CLIENT_SHADER_H
#define CLIENT_SHADER_H

#include <iostream>
#include <GL/glew.h>

#include "../maths/Vec2.h"
#include "../maths/Vec3.h"
#include "../maths/Vec4.h"
#include "../maths/Mat4.h"
#include "../utils/File.h"

namespace graphics {
    using namespace maths;
    using namespace utils;

    class Shader {
    public: // @todo make <- private
        GLuint m_ShaderID;
        const char *m_VertexPath;
        const char *m_FragmentPath;

        GLint getUniformLocation(const GLchar *);
        GLuint compile(const char *, GLuint);
        GLuint compileStatus(GLuint);

    public:
        Shader(const char *, const char *);
        ~Shader();

        void enable() const;

        void setUniform1i(const GLchar *, int);
        void setUniform1f(const GLchar *, float);
        void setUniform2f(const GLchar *, Vec2 &);
        void setUniform3f(const GLchar *, Vec3 &);
        void setUniform4f(const GLchar *, Vec4 &);
        void setUniformMat4(const GLchar *, const maths::Mat4 &);
    };
}

#endif //CLIENT_SHADER_H
