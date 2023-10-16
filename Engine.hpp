#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

class Renderable;
class Renderer;

class Engine {
 public:
  void run();
  void addRenderable(const Renderable* go);

  static Engine* getInstance();
  static void shutdown();

 private:
  Engine();
  virtual ~Engine();

  static Engine* instance;

  static constexpr int WINDOW_WIDTH = 1280;
  static constexpr int WINDOW_HEIGHT = 720;

  Renderer* renderer;

  unsigned int chessboardTexture;
  std::vector<const Renderable*> renderables;

  GLFWwindow* window;

  void initOpenGL() const;
  void initWindow();
  void initGlad() const;
  void processInput() const;
  void clearRenderables();
};

#endif