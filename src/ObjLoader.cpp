#include <vector>
#include <glm/glm.hpp>
#include "spdlog/spdlog.h"
#include "ObjLoader.hpp"
#include "Triangle.hpp"

using namespace glm;
using namespace std;

ObjLoader::ObjLoader()
{
  spdlog::info( "Obj loader created" );
}

bool ObjLoader::import( std::string filename )
{
  spdlog::info( "Importing file {}", filename );
  this->importer = new Assimp::Importer();
  this->scene = this->importer->ReadFile( filename, aiProcessPreset_TargetRealtime_Quality );
  if(this->scene == NULL)
  {
    spdlog::error( "ObjLoader::import: Failed to import the file {}", filename );
    return false;
  }
  this->importer->SetPropertyInteger( AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT );
  spdlog::info( "File {} imported successfully", filename );
  return true;
}

bool ObjLoader::loadShapes( std::vector<Shape*> &shapes )
{
  spdlog::info( "Loading shapes" );
  if( this->scene == NULL )
  {
    spdlog::error( "Loader::loadData: No scene loaded" );
    return false;
  }
  spdlog::info( "Number of meshes: {}", this->scene->mNumMeshes );
  if( this->scene->HasMeshes() )
  {
    for( unsigned int i = 0; i < this->scene->mNumMeshes; i++ )
    {
      aiMesh *mesh = this->scene->mMeshes[ i ];
      spdlog::debug( "Mesh {}", i );
      // aiMaterial *mtl = scene->mMaterials[mesh->mMaterialIndex];
      // aiColor4D aiDiffuse;
      // Color diffuse;
      // if(aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &aiDiffuse) == AI_SUCCESS)
      // {
      //   diffuse.set_red(aiDiffuse.r);
      //   diffuse.set_green(aiDiffuse.g);
      //   diffuse.set_blue(aiDiffuse.b);
      // }
      //
      // aiColor4D aiSpecular;
      // Color specular;
      // if(aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &aiSpecular) == AI_SUCCESS)
      // {
      //   specular.set_red(aiSpecular.r);
      //   specular.set_green(aiSpecular.g);
      //   specular.set_blue(aiSpecular.b);
      // }
      //
      // aiColor4D aiAmbient;
      // Color ambient;
      // if(aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &aiAmbient) == AI_SUCCESS)
      // {
      //   ambient.set_red(aiAmbient.r);
      //   ambient.set_green(aiAmbient.g);
      //   ambient.set_blue(aiAmbient.b);
      // }
      // float shininess = 0.f;
      // float aiShininess = 0.f;
      // if(aiGetMaterialFloat(mtl, AI_MATKEY_SHININESS, &aiShininess) == AI_SUCCESS)
      // {
      //   shininess = aiShininess;
      // }
      // Material material(ambient, diffuse, specular, shininess);

      vector<vec3> positions;
      spdlog::debug( "Number of vertices: {}", mesh->mNumVertices );
      for( unsigned int j = 0; j < mesh->mNumVertices; j++ )
      {
        const aiVector3D& position = mesh->mVertices[ j ];
        spdlog::debug( "Vertice {}: {} {} {}", j, position.x, position.y, position.z );
        vec3 v = vec3( position.x, position.y, position.z );
        positions.push_back( v );
      }
      spdlog::debug( "Vertices loaded" );

      spdlog::debug( "Number of faces: {}", mesh->mNumFaces );
      for( unsigned int j = 0; j < mesh->mNumFaces; j++ )
      {
        const aiFace& face = mesh->mFaces[ j ];
        if( face.mNumIndices == 3 )
        {
          vec3 p1 = positions[ face.mIndices[ 0 ] ];
          vec3 p2 = positions[ face.mIndices[ 1 ] ];
          vec3 p3 = positions[ face.mIndices[ 2 ] ];
          Triangle *t = new Triangle( p1, p2, p3 );
          shapes.push_back(t);
        }
      }
      spdlog::debug( "Faces loaded" );
    }
  }
  spdlog::info( "Meshes loaded successfully" );
  return true;
}
