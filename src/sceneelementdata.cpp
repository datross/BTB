#include "sceneelementdata.hpp"

using namespace std;

SceneElementData::SceneElementData(int elementID , const MapData& map_data) : elementID(elementID), map_data(map_data), emerged(false)
{
  if(elementID >= static_cast<int>(map_data.scene_data.size()))
    throw invalid_argument("The ID of the SceneElement is incorrect.");
}

bool SceneElementData::hasToEmerge(const sf::Time& timeElapsed) const
{
  return !emerged && timeElapsed >= getEmergence() && timeElapsed <= getEmergence() + getDuration();
}

void SceneElementData::emerge()
{
  emerged = true;
}

void SceneElementData::kill()
{
  emerged = false;
}


sf::Time SceneElementData::getClickTime() const
{
  return map_data.scene_data[elementID].time;
}

sf::Time SceneElementData::getDuration() const
{
  return map_data.scene_data[elementID].duration;
}

float SceneElementData::getRatio() const
{
  return map_data.scene_data[elementID].ratio;
}

string SceneElementData::getType() const
{
  return map_data.scene_data[elementID].type;
}

sf::Time SceneElementData::getEmergence() const
{
  return getClickTime() - getRatio() * getDuration();
}
