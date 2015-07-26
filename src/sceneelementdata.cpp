#include "sceneelementdata.hpp"

using namespace std;

SceneElementData::SceneElementData(int elementID , const MapData& map_data) : elementID(elementID), map_data(map_data)
{
  if(elementID >= static_cast<int>(map_data.scene_data.size()))
    throw invalid_argument("The ID of the SceneElement is incorrect.");
}

sf::Time SceneElementData::getTime() const
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

bool SceneElementData::isActive(const sf::Time& timeElapsed) const
{
  return timeElapsed >= getTime() && timeElapsed <= getTime() + getDuration();
}

sf::Time SceneElementData::getEmergence() const
{
  return getTime() - getRatio() * getDuration();
}
