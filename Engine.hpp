#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include "Renderable.hpp"
#include "Renderer.hpp"

class Engine {
 public:
  Engine();
  virtual ~Engine();

  void run();
  void initOpenGL() const;
  void initWindow();
  void initGlad() const;
  void processInput() const;
  void addRenderable(const Renderable* go);

 private:
  static constexpr int WINDOW_WIDTH = 1280;
  static constexpr int WINDOW_HEIGHT = 720;

  Renderer* renderer;

  unsigned int chessboardTexture;
  std::vector<const Renderable*> renderables;

  GLFWwindow* window;
};

#endif