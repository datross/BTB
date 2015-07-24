#include "sceneelementdata.hpp"

using namespace std;

SceneElementData::SceneElementData(int elementID , const MapData& map_data) : elementID(elementID), map_data(map_data)
{
  if(elementID >= static_cast<int>(map_data.sceneData.size()))
    throw invalid_argument("The ID is incorrect.");
}

float SceneElementData::getTime()
{
  return map_data.sceneData[elementID].time;
}

float SceneElementData::getDuration()
{
  return map_data.sceneData[elementID].duration;
}

float SceneElementData::getRatio()
{
  return map_data.sceneData[elementID].ratio;
}

string SceneElementData::getType()
{
  return map_data.sceneData[elementID].type;
}


