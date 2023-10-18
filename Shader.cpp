
#include "Shader.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

unsigned int compileShader(const char* shaderSource,
                           const unsigned int shaderType) {
  unsigned int shader;
  int success;
  char infoLog[512];

  shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &shaderSource, NULL);
  glCompileShader(shader);

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cerr << "[-] Shader Error at: failed to compile shader" << std::endl;
    std::cerr << infoLog << std::endl;
  }

  return shader;
}

unsigned int createShaderProgram(unsigned int vertex, unsigned int fragment) {
  unsigned int id = glCreateProgram();
  glAttachShader(id, vertex);
  glAttachShader(id, fragment);
  glLinkProgram(id);

  int success;
  char infoLog[512];

  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id, 512, NULL, infoLog);
    std::cerr << "[-] Shader Error at: failed to link shader program"
              << std::endl;
    std::cerr << infoLog << std::endl;
  }

  glDeleteShader(vertex);
  glDeleteShader(fragment);

  return id;
}

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;

  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);
    std::stringstream vShaderStream, fShaderStream;

    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    vShaderFile.close();
    fShaderFile.close();

    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();
  } catch (std::ifstream::failure e) {
    std::cerr << "[-] Shader Error: failed to read files" << std::endl;
  }

  const char* vShaderCode = vertexCode.c_str();
  const char* fShaderCode = fragmentCode.c_str();

  unsigned int vertex, fragment;

  vertex = compileShader(vShaderCode, GL_VERTEX_SHADER);
  fragment = compileShader(fShaderCode, GL_FRAGMENT_SHADER);
  this->ID = createShaderProgram(vertex, fragment);
}

Shader::~Shader() { glDeleteProgram(this->ID); };

void Shader::use() const { glUseProgram(this->ID); };

void Shader::setBool(const std::string& name, const bool value) const {
  glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, const int value) const {
  glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, const float value) const {
  glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
  glUniform3fv(glGetUniformLocation(this->ID, name.c_str()), 1, &value[0]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& value) const {
  glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE,
                     &value[0][0]);
}

unsigned int Shader::getID() const { return this->ID; }