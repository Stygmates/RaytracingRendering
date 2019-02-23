#include "spdlog/spdlog.h"
#include "ObjLoader.hpp"

using namespace std;
int main()
{
  spdlog::set_level(spdlog::level::debug);
  ObjLoader obj;
  return 0;
}
