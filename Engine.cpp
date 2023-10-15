#include "Engine.hpp"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Engine::Engine() {
  this->initOpenGL();
  this->initWindow();
}

Engine::~Engine() { glfwTerminate(); }

void Engine::initOpenGL() const {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void Engine::initWindow() {
  this->window =
      glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", nullptr, nullptr);

  if (this->window == nullptr) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();

    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(this->window);

  this->initGlad();

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glfwSetFramebufferSizeCallback(this->window, frameBufferSizeCallback);
}

void Engine::initGlad() const {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;

    exit(EXIT_FAILURE);
  }
}

void Engine::processInput() const {
  if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(this->window, true);
  }
}

void Engine::render() const {
  // render commands
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  for (const Renderable* re : this->renderables) {
    re->render();
  }
}

void Engine::run() {
  while (!glfwWindowShouldClose(this->window)) {
    // input checks
    this->processInput();

    // rendering commands
    this->render();

    // checks events and swap buffers
    glfwSwapBuffers(this->window);
    glfwPollEvents();
  }
}

void Engine::addRenderable(const Renderable* go) {
  this->renderables.push_back(go);
}