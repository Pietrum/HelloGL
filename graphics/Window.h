#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../inputs/Keyboard.h"
#include "../inputs/Mouse.h"

namespace graphics {

    class Window {
        const char* m_Title;
        int m_Width, m_Height;
        GLFWwindow* m_Window;

        public:
        Window(int, int, const char*);
        ~Window();

        bool init();
        void clear() const;
        void update() const;
        bool closed() const;
    };

}


#endif //CLIENT_WINDOW_H
