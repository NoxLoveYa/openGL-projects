/*
** EPITECH PROJECT, 2023
** HelloWorld
** File description:
** main
*/

#include "include/main.hpp"

const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

Renderer *render;

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float camSpeed = render->cameraSpeed * render->deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        render->cameraPos += camSpeed * render->cameraFront;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        render->cameraPos -= camSpeed * render->cameraFront;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        render->cameraPos -= glm::normalize(glm::cross(render->cameraFront, render->cameraUp)) * camSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        render->cameraPos += glm::normalize(glm::cross(render->cameraFront, render->cameraUp)) * camSpeed;
    }   
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    render->fov -= (float)yoffset;
    if (render->fov < 1.0f)
        render->fov = 1.0f;
    if (render->fov > 90.0f)
        render->fov = 90.0f; 
}


float lastX = SCR_WIDTH / 2, lastY = SCR_HEIGHT / 2;
bool firstMouse = true;
float yaw = -89.0f, pitch = 0.0f;

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
  
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 2.5f * render->deltaTime;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    render->cameraFront = glm::normalize(direction);
}  

int main()
{
    GLFWwindow *window;

    if (!glfwInit())    
        return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    register_callbacks(window);

    glEnable(GL_DEPTH_TEST);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    Renderer ctx = Renderer();
    render = &ctx;

    ctx.fov = 60.0f;

    //wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    float lastFrame = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        ctx.deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        //process input
        processInput(window);

        //rendering commands here
        glClearColor(0.f, 0.f, 0.f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Color color = {1.0f, 0.5f, 0.31f};
        Color light_color = {1.0f, 1.0f, 1.0f};

        //LightSource
        ctx.cube(glm::vec3(1.2f, 1.0f, 2.0f), light_color, light_color, ctx.SHADERS[FLAT_LIGHT].shader);
        //cubes
        ctx.cube(glm::vec3(0.0f, 0.0f,  0.0f), color, light_color, ctx.SHADERS[FLAT3D].shader);

        //check and call events and swap the buffers to prevent flickering
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
