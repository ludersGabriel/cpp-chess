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

  int getWindowWidth() const;
  int getWindowHeight() const;

 private:
  Engine();
  virtual ~Engine();

  static Engine* instance;

  int windowWidth = 1600;
  int windowHeight = 900;

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