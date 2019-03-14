#include "Camera.hpp"

using namespace glm;
using namespace std;

Camera::Camera(vec3 origin, vec3 direction, vec3 up, int angle_of_view, int size): origin(origin), direction(direction), up(up), angle_of_view(angle_of_view), size(size)
{
}


vector<vector<vec3>> Camera::render(vector<Shape*> shapes)
{
  vector<vector<vec3>> frame(size, vector<vec3>(size));
  return frame;
}
