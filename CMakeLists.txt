cmake_minimum_required (VERSION 3.0)
project (Raytracing)
set (Raytracing_VERSION_MAJOR 0)
set (Raytracing_VERSION_MINOR 1)

set(SOURCES
    src/main.cpp
    src/Triangle.cpp
    src/ObjLoader.cpp
)


#ASSIMP
find_package(ASSIMP REQUIRED)
if(ASSIMP_FOUND)
    include_directories(${ASSIMP_INCLUDE_DIR})
endif()

#GLM
find_package(glm REQUIRED)
if(GLM_FOUND)
    include_directories(${GLM_INCLUDE_DIR})
endif()

add_executable(Raytracing ${SOURCES})

target_include_directories(Raytracing
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Raytracing ${ASSIMP_LIBRARIES})
target_link_libraries(Raytracing ${GLM_LIBRARY})
