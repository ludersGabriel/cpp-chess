#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

class Texture {
 public:
  Texture(const std::string& path);
  virtual ~Texture();

  unsigned int getID() const;

 private:
  unsigned int textureID;

  void loadTexture(const std::string& path);
};

#endif