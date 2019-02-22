#ifndef __SHAPE_HPP
#define __SHAPE_HPP
#include <vector>
#include <glm/glm.hpp>

class Shape{
public:
  virtual bool intersects_ray() = 0;
private:
};

#endif
