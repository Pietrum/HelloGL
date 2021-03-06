#ifndef CLIENT_MOUSE_H
#define CLIENT_MOUSE_H

#include <iostream>
#include <GLFW/glfw3.h>

#define MAX_BUTTONS 32

namespace Input {
    class Mouse {
    public: // make <- public
        static bool m_Buttons[MAX_BUTTONS];
        static double x, y;
    public:
        static void actionCallback(GLFWwindow *, int, int, int);
        static void positionCallback(GLFWwindow *, double, double);
        static bool isButtonPressed(unsigned int);
    };
}

#endif //CLIENT_MOUSE_H
