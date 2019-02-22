#include "Triangle.hpp"
Triangle::Triangle()
{

}

Triangle::Triangle( glm::vec3 p1, glm::vec3 p2, glm::vec3 p3 )
{
  vertices[0] = p1;
  vertices[1] = p2;
  vertices[2] = p3;
}

bool Triangle::intersects_ray()
{
  return true;
}
