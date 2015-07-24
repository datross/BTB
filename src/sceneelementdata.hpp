/*** This file contains an abstract class for using the scene element data ***/

#ifndef SCENE_ELEMENT_DATA
#define SCENE_ELEMENT_DATA

#include "mapdata.hpp"
#include <stdexcept>

class SceneElementData
{
public :
  SceneElementData(int elementID , const MapData& a_map_data);
  double getTime();
  double getDuration();

private : 
  const MapData& map_data;
  int elementID;
};


#endif //SCENE_ELEMENT_DATA
