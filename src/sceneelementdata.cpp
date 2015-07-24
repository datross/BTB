#include "sceneelementdata.hpp"

SceneElementData::SceneElementData(int elementID , const MapData& map_data) : elementID(elementID), map_data(map_data)
{
  if(elementID >= static_cast<int>(map_data.sceneData.size()))
    throw std::out_of_range("The ID is incorrect.");
}

double SceneElementData::getTime()
{
  return map_data.sceneData[elementID].time;
}

double SceneElementData::getDuration()
{
  return map_data.sceneData[elementID].duration;
}
