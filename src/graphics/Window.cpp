#include "Window.h"

namespace graphics {
    Window::Window(int width, int height, const char *title)
            : m_Title(title), m_Width(width), m_Height(height) {
        if (!init()) {
            glfwTerminate();
        };
    }

    Window::~Window() {
        glfwTerminate();
    }

    bool Window::init() {
        // initialize the library
        if (glfwInit() == GLFW_FALSE) {
            std::cout << "Failed to initialize GLFW!" << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        // make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // create a windowed mode window and its OpenGL context
        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);

        if (m_Window == GLFW_FALSE) {
            std::cout << "Failed to create GLFW window!" << std::endl;
            return false;
        }

        // make the window context current
        glfwMakeContextCurrent(m_Window);

        // inputs
        glfwSetKeyCallback(m_Window, Keyboard::actionCallback);
        glfwSetMouseButtonCallback(m_Window, Mouse::actionCallback);
        glfwSetCursorPosCallback(m_Window, Mouse::positionCallback);

        // needed for core profile
        glewExperimental = GL_TRUE;
        // initialize the library
        if (glewInit() != GLEW_OK) {
            std::cout << "Failed to initialize GLEW!" << std::endl;
            return false;
        }

        // debug info
        std::cout << glGetString(GL_VERSION) << std::endl;

        return true;
    }

    void Window::clear() const {
        // render
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::update() const {
        // swap front and back buffers
        glfwSwapBuffers(m_Window);

        // poll for and process events
        glfwPollEvents();
    }

    bool Window::closed() const {
        return glfwWindowShouldClose(m_Window) == GLFW_TRUE ||      // for test only
               Input::Keyboard::isKeyPressed(GLFW_KEY_ESCAPE) ||       // exit after pressed ESC
               Input::Mouse::isButtonPressed(GLFW_MOUSE_BUTTON_3);     // exit after scroll/middle button
    }
}
