/*** This file contains an abstract class for using the scene element data ***/

#ifndef SCENE_ELEMENT_DATA
#define SCENE_ELEMENT_DATA

#include "mapdata.hpp"
#include <stdexcept>
#include <string>

class SceneElementData
{
public :
  SceneElementData(int elementID , const MapData& map_data);

  //accessors
  float getTime();
  float getDuration();
  float getRatio();
  std::string getType();

protected : 
  const MapData& map_data;
  int elementID;
};


#endif //SCENE_ELEMENT_DATA
