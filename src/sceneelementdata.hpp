/*** This file contains an abstract class for using the scene element data ***/

#ifndef SCENE_ELEMENT_DATA
#define SCENE_ELEMENT_DATA

#include "mapdata.hpp"
#include <SFML/System.hpp>
#include <stdexcept>
#include <string>

sf::Vector2f parsePosition(const json& json_position);


class SceneElementData
{
public :
  SceneElementData(int elementID , const MapData& map_data);

  //accessors
  sf::Time getClickTime() const;
  sf::Time getDuration() const;
  sf::Time getEmergence() const;
  float getRatio() const;
  std::string getType() const;

  bool hasToEmerge(const sf::Time& timeElapsed) const;
  void emerge();
  void kill();


  class EmergenceComparison
  {
  public :
    bool operator()(const SceneElementData& sed1, const SceneElementData& sed2)
    {
      return sed1.getEmergence() <= sed2.getEmergence();
    }
  };

  class ClickComparison
  {
  public :
    bool operator()(const SceneElementData* sed1, const SceneElementData* sed2)
    {
      return sed1->getClickTime() <= sed2->getClickTime();
    }
  };

protected : 
  const MapData& map_data;
  int elementID;
  bool emerged;
};


#endif //SCENE_ELEMENT_DATA
