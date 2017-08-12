#ifndef CLIENT_SHADER_H
#define CLIENT_SHADER_H

#include <iostream>
#include <GL/glew.h>

#include "../utils/File.h"

class Shader {

    public:
    GLuint m_ShaderID;
    const char* m_VertexPath;
    const char* m_FragmentPath;

    GLuint compile(const char*, GLuint);
    GLuint compileStatus(GLuint);

    public:
    Shader(const char*, const char*);
    ~Shader();
    void enable() const;

};


#endif //CLIENT_SHADER_H
