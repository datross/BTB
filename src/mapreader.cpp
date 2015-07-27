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

//This function returns the elements which have never been displayed before but which have to be displayed starting from now.
vector<SceneElementData*> MapReader::getNewElements()
{
  vector<SceneElementData*> ret;
  for(int i = 0; i < static_cast<int>(scene_elements.size()); i++)
    {
      if(scene_elements[i]->hasToEmerge(clock.getElapsedTime()))
	{
	  ret.push_back(scene_elements[i]);
	  scene_elements[i]->emerge();
	}
    }
  std::sort(ret.begin(),ret.end(),SceneElementData::ClickComparison());
  return ret;
}


//This function return the time elapsed since the begining of the song
sf::Time MapReader::getTime()
{
  return clock.getElapsedTime();
}

MapReader::~MapReader()
{
  for( int i; i < static_cast<int>(map_data.scene_data.size()); i++)
    delete scene_elements[i];
}
