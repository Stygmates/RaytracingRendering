#include "spdlog/spdlog.h"
#include "ObjLoader.hpp"
#include "CLI11.hpp"

using namespace std;
int main(int argc, char **argv)
{
  CLI::App app{"Raytracing"};
  std::string filename = "Yuna.obj";
  app.add_option( "-f,--file", filename, "The obj to load" );
  CLI11_PARSE( app, argc, argv );

  spdlog::set_level( spdlog::level::debug );
  ObjLoader obj;
  if( !obj.import( filename ) )
  {
    spdlog::error( "Failed to import file {}", filename );
    return -1;
  }
  vector<Shape*> shapes;
  if( !obj.loadShapes( shapes ) )
  {
    spdlog::error( "Failed to load the shapes" );
    return -1;
  }

  return 0;
}
