#ifndef CLIENT_KEYBOARD_H
#define CLIENT_KEYBOARD_H

#include <iostream>
#include <GLFW/glfw3.h>

#define MAX_KEYS	1024

namespace Input {

    class Keyboard {
        static bool m_Keys[MAX_KEYS];

        public:
        static void actionCallback(GLFWwindow*, int, int, int, int);
        static bool isKeyPressed(unsigned int);
    };

}

#endif //CLIENT_KEYBOARD_H
