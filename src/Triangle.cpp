#include "Triangle.hpp"
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/intersect.hpp>
Triangle::Triangle()
{

}

Triangle::Triangle( glm::vec3 p1, glm::vec3 p2, glm::vec3 p3 )
{
  vertices[0] = p1;
  vertices[1] = p2;
  vertices[2] = p3;
}

bool Triangle::intersects_ray( Ray r )
{
  glm::vec2 barycentre;
  float distance;
  distance = 10;
  distance = 5;
  return glm::intersectRayTriangle( r.get_origin(), r.get_direction(), vertices[ 0 ], vertices[ 1 ], vertices[ 2 ], barycentre, distance);
}
