#ifndef __TRIANGLE_HPP
#define __TRIANGLE_HPP

#include "Shape.hpp"
#include <glm/glm.hpp>

class Triangle: public Shape{
public:
  Triangle();
  Triangle( glm::vec3 p1, glm::vec3 p2, glm::vec3 p3 );
  bool intersects_ray();
private:
  glm::vec3 vertices[3];
};

#endif
