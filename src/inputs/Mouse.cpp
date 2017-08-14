#include "Mouse.h"

namespace Input {
    bool Mouse::m_Buttons[MAX_BUTTONS];
    double Mouse::x, Mouse::y;

    void Mouse::actionCallback(GLFWwindow *window, int button, int action, int mods) {
        m_Buttons[button] = action != GLFW_RELEASE;
    }

    void Mouse::positionCallback(GLFWwindow *window, double xpos, double ypos) {
        x = xpos;
        y = ypos;
    }

    bool Mouse::isButtonPressed(unsigned int button) {
        if (button >= MAX_BUTTONS)
            return false;

        return m_Buttons[button];
    }
}
