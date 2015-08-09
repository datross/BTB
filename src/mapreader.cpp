#include "mapreader.hpp"

using namespace std;

MapReader::MapReader(const MapData& map_data) : map_data(map_data),scene_elements(map_data.scene_data.size()), last_id_not_displayed(0)
{
  //loading all the scene elements
  for(int i = 0; i<static_cast<int>(map_data.scene_data.size());i++)
    {
      if (map_data.scene_data[i].type == "circle")
	scene_elements[i] = new SceneCircleData(i,map_data); 
      else
	throw invalid_argument("The string \"" + map_data.scene_data[i].type + "\" doesn't name a type.");
    }
  std::sort(scene_elements.begin(),scene_elements.end(),SceneElementData::EmergenceComparison());
}

void MapReader::startSong()
{
  map_data.song->play();
}

//This function returns the elements which have never been displayed before but which have to be displayed starting from now.
vector<SceneElementData*> MapReader::getNewElements(const sf::Time& time)
{
  vector<SceneElementData*> ret;
  int i = last_id_not_displayed;
  sf::Time max_click_time = sf::milliseconds(0);

  //looking forthe elements to emerge
  while(i < static_cast<int>(scene_elements.size()) && scene_elements[i]->getEmergence() <= time)
    {
      if(scene_elements[i]->hasToEmerge(time))
	{
	  ret.push_back(scene_elements[i]);
	  scene_elements[i]->emerge();
	}
      if(scene_elements[i]->getClickTime() > max_click_time)
	max_click_time = scene_elements[i]->getClickTime();
      i++;
    }
  last_id_not_displayed = i;

  //looking for the elements which have their clickTime before the emerging elements' clickTime.
  while(i < static_cast<int>(scene_elements.size()) && scene_elements[i]->getEmergence() <= max_click_time)
    {
      if(scene_elements[i]->getClickTime() <= max_click_time)
	{
	  ret.push_back(scene_elements[i]);
	  scene_elements[i]->emerge();
	}
      i++;
    }
  
  //sorting by click order
  std::sort(ret.begin(),ret.end(),SceneElementData::ClickComparison());
  return ret;
}

MapReader::~MapReader()
{
  for( int i = 0; i < static_cast<int>(map_data.scene_data.size()); i++)
    delete scene_elements[i];
}
