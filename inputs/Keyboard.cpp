#include "Keyboard.h"

namespace Input {

    bool Keyboard::m_Keys[MAX_KEYS];

    void Keyboard::actionCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        m_Keys[key] = action != GLFW_RELEASE;
    }

    bool Keyboard::isKeyPressed(unsigned int keycode) {
        if (keycode >= MAX_KEYS)
            return false;

        return m_Keys[keycode];
    }

}