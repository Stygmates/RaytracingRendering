#ifndef __SHAPE_HPP
#define __SHAPE_HPP
#include <vector>
#include <glm/glm.hpp>
#include "Ray.hpp"

class Shape{
public:
  virtual bool intersects_ray(Ray r) = 0;
private:
};

#endif
