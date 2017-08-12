#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
    : m_VertexPath(vertexPath), m_FragmentPath(fragmentPath) {

    GLuint vertexID = compile(vertexPath, GL_VERTEX_SHADER);
    GLuint fragmentID = compile(fragmentPath, GL_FRAGMENT_SHADER);

    m_ShaderID = glCreateProgram();
    glAttachShader(m_ShaderID, vertexID);
    glAttachShader(m_ShaderID, fragmentID);

    glLinkProgram(m_ShaderID);
    glValidateProgram(m_ShaderID);

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
}

Shader::~Shader() {
    glDeleteProgram(m_ShaderID);
}

GLint Shader::getUniformLocation(const GLchar* name) {
    return glGetUniformLocation(m_ShaderID, name);
}

GLuint Shader::compile(const char* shaderPath, GLuint shaderType) {
    // read shader source file
    const char* source = File::readFile(shaderPath);

    // create
    GLuint compileID = glCreateShader(shaderType);
    glShaderSource(compileID, 1, &source, nullptr);
    glCompileShader(compileID);

    return compileStatus(compileID);
}

GLuint Shader::compileStatus(GLuint compileID) {
    GLint status;

    glGetShaderiv(compileID, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint errorLength;
        glGetShaderiv(compileID, GL_INFO_LOG_LENGTH, &errorLength);
        auto * errorMessage = new GLchar[errorLength + 1];
        glGetShaderInfoLog(compileID, errorLength, nullptr, errorMessage);
        std::cout << "[" << compileID << "] Failed to compile shader!" << std::endl << errorMessage << std::endl;
        glDeleteShader(compileID);

        return 0;
    }

    return compileID;
}

void Shader::enable() const {
    glUseProgram(m_ShaderID);
}

void Shader::setUniformMat4(const GLchar* name, const Mat4& matrix) {
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.e);
}