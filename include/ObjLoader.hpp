#ifndef __OBJLOADER_HPP
#define __OBJLOADER_HPP

#include <string>
#include <vector>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include "Shape.hpp"


/**
* @brief The Loader class: Helper class that loads an obj into an array of triangles
*/
class ObjLoader{
public:
  /**
  * @brief Loader Loader constructor
  */
  ObjLoader();

  /**
  * @brief import Import the file specified with filename
  * @param filename The path to the obj
  */
  bool import( std::string filename );

  /**
  * @brief loadData Loads the triangles into an array of triangles
  * @param triangles The array of triangles where the triangles from the obj will be stored
  */
  bool loadShapes( std::vector<Shape*> &shapes );
private:
  /**
  * @brief scene Necessary attribute to use assimp
  */
  const aiScene *scene;

  /**
  * @brief importer Necessary attribute to use assimp
  */
  Assimp::Importer *importer;
};

#endif
