/*** This file contains the class SceneCircleData which provides data support for the circle element display. ***/

#ifndef SCENE_CIRCLE_DATA
#define SCENE_CIRCLE_DATA

#include "sceneelementdata.hpp"
#include "utils.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

class SceneCircleData : public SceneElementData
{
public :
  SceneCircleData(int circleID, const MapData& map_data);  
  
  int getRadius() const;
  sf::Color getColor() const;
  

};

#endif //SCENE_CIRCLE_DATA
