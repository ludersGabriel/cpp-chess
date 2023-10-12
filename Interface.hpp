#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Interface {
 public:
  Interface();
  virtual ~Interface();

  void run();
  void initOpenGL() const;
  void initWindow();
  void initGlad() const;
  void loadTextures() const;
  void render() const;
  void processInput() const;

 private:
  static constexpr int WINDOW_WIDTH = 1280;
  static constexpr int WINDOW_HEIGHT = 720;

  GLFWwindow* window;
};

#endif