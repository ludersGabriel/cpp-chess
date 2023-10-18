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

  static constexpr int WINDOW_WIDTH = 800;
  static constexpr int WINDOW_HEIGHT = 800;
  float aspectRatio = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;

  Renderer* renderer;

  std::vector<const Renderable*> renderables;

  GLFWwindow* window;

  void initOpenGL() const;
  void initWindow();
  void initGlad() const;
  void processInput() const;
  void clearRenderables();

  static void frameBufferSizeCallback(GLFWwindow* window, int width,
                                      int height);
};

#endif