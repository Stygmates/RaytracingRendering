#ifndef __CAMERA_HPP
#define __CAMERA_HPP
#include <glm/glm.hpp>
#include "Shape.hpp"
#include <vector>

class Camera {
public:
  Camera(glm::vec3 origin, glm::vec3 direction, glm::vec3 up, int angle_of_view, int size);
  std::vector< std::vector < glm::vec3 > > render(std::vector<Shape*> shapes);
private:
  glm::vec3 origin;
  glm::vec3 direction;
  glm::vec3 up;
  int angle_of_view;
  int size;
};

#endif
