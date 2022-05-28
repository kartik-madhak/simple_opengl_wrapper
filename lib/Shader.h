#ifndef OPENGL_TEST_SHADER_H
#define OPENGL_TEST_SHADER_H

#include <string>
#include <glad/glad.h>

namespace SOW {

    class Shader {

    public:
        Shader(std::string sourcePath, GLenum shaderType);

        [[nodiscard]] unsigned int getId() const;

    private:
        unsigned id;
        GLenum shaderType;
        std::string sourcePath;
        std::string source;
    };

} // SOW

#endif //OPENGL_TEST_SHADER_H
