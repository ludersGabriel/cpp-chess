#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <string>

class Shader {
 public:
  static constexpr const char* defaultVertexShader = "./shaders/shader.vs";
  static constexpr const char* defaultFragmentShader = "./shaders/shader.fs";

  Shader(const std::string& vertexPath = defaultVertexShader,
         const std::string& fragmentPath = defaultFragmentShader);

  virtual ~Shader();

  void use() const;

  void setBool(const std::string& name, const bool value) const;
  void setInt(const std::string& name, const int value) const;
  void setFloat(const std::string& name, const float value) const;
  void setVec3(const std::string& name, const glm::vec3& value) const;
  void setMat4(const std::string& name, const glm::mat4& value) const;

  unsigned int getID() const;

 private:
  unsigned int ID;
};

#endif