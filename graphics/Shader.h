#ifndef CLIENT_SHADER_H
#define CLIENT_SHADER_H

#include <iostream>
#include <GL/glew.h>

#include "../maths/Mat4.h"
#include "../utils/File.h"

class Shader {

    public:
    GLuint m_ShaderID;
    const char* m_VertexPath;
    const char* m_FragmentPath;

    GLint getUniformLocation(const GLchar*);
    GLuint compile(const char*, GLuint);
    GLuint compileStatus(GLuint);

    public:
    Shader(const char*, const char*);
    ~Shader();
    void enable() const;

    void setUniformMat4(const GLchar* name, const Mat4& matrix);

};


#endif //CLIENT_SHADER_H
