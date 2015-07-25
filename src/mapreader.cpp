#include "mapreader.hpp"

using namespace std;

MapReader::MapReader(const MapData& map_data) : map_data(map_data),scene_elements(map_data.scene_data.size()), ids_displayed(0)
{
  //loading all the scene elements
  for(int i; i<static_cast<int>(map_data.scene_data.size());i++)
    {
      if (map_data.scene_data[i].type == "circle")
	scene_elements[i] = new SceneCircleData(i,map_data);
      else
	throw invalid_argument("The string \"" + map_data.scene_data[i].type + "\" doesn't name a type.");
    }
}

void MapReader::startSong()
{
  clock.restart();
  map_data.song->play();
}

const SceneElementData& MapReader::getSceneElementData(int id)
{
  return (*scene_elements[id]);
}

vector<int> idsToDisplay()
{
  
}

vector<int> idsToRemove()
{
  
}

MapReader::~MapReader()
{
  for( int i; i < static_cast<int>(map_data.scene_data.size()); i++)
    delete scene_elements[i];
}
