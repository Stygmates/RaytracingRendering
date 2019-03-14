#ifndef __RAY_HPP
#define __RAY_HPP

#include <glm/glm.hpp>

class Ray{
public:
  Ray(glm::vec3 origin, glm::vec3 direction);
  glm::vec3 get_origin();
  glm::vec3 get_direction();
private:
  glm::vec3 origin;
  glm::vec3 direction;
};

#endif
