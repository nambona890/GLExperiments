#include "window.h"
#include "shaders.h"
#include "surface.h"

NamWindow::NamWindow()
{
    
}

int NamWindow::Start()
{
    GLFWwindow* window;
    glewExperimental = true;
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREENWIDTH, SCREENHEIGHT, "Penis", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewInit();

    unsigned int mandelVS = CreateShader("Shaders\\MandelVS.vert", GL_VERTEX_SHADER);
    unsigned int mandelFS = CreateShader("Shaders\\MandelFS.frag", GL_FRAGMENT_SHADER);
    unsigned int mandelSP = CreateProgram(mandelVS, mandelFS);

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleInd), triangleInd, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_DOUBLE, GL_FALSE, 6 * sizeof(double), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE, 6 * sizeof(double), (void*)(4 * sizeof(double)));
    glEnableVertexAttribArray(1);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        double startTime = glfwGetTime();

        /* Render here */
        glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(mandelSP);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_DYNAMIC_DRAW);

        unsigned int iterations = glGetUniformLocation(mandelSP, "iterations");
        glUniform1i(iterations, 1024);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);


        double endTime = glfwGetTime() - startTime;
        char title[256];
        title[255] = '\0';
        snprintf(title, 255, "%3.3f", (float)endTime);
        glfwSetWindowTitle(window, title);

        /* Poll for and process events */
        glfwPollEvents();
        Vec2 cursor;
        glfwGetCursorPos(window, &cursor.x, &cursor.y);
        cursor = ScreenNormalize(cursor);

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            offset.x -= (cursor.x - pMouse.x) / (scale.x);
            offset.y -= (cursor.y - pMouse.y) / (scale.y);
        }
        pMouse = cursor;

        Vec2 bMouse = StW(cursor);

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            scale.x *= 1+ (2 * endTime);
            scale.y *= 1+ (2 * endTime);
        }
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            scale.x /= 1 + (2 * endTime);
            scale.y /= 1 + (2 * endTime);
        }

        Vec2 aMouse = StW(cursor);
        offset.x += (bMouse.x - aMouse.x);
        offset.y += (bMouse.y - aMouse.y);

        triangle[0].u = tl.x / scale.x + offset.x;
        triangle[0].v = tl.y / scale.y + offset.y;

        triangle[1].u = br.x / scale.x + offset.x;
        triangle[1].v = br.y / scale.y + offset.y;

        triangle[2].u = br.x / scale.x + offset.x;
        triangle[2].v = tl.y / scale.y + offset.y;

        triangle[3].u = tl.x / scale.x + offset.x;
        triangle[3].v = br.y / scale.y + offset.y;
    }

    glfwTerminate();
    return 0;
}
