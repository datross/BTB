#include "mapreader.hpp"

#define MISSED -50

using namespace std;

MapReader::MapReader(const MapData& map_data) : map_data(map_data),scene_elements(map_data.scene_data.size()), last_id_not_displayed(0), score(0), last_id_not_clicked(0)
{
  //loading all the scene elements
  for(int i = 0; i<static_cast<int>(map_data.scene_data.size());i++)
    {
      if (map_data.scene_data[i].type == "circle")
	scene_elements[i] = new SceneCircleData(i,map_data); 
      else
	throw invalid_argument("The string \"" + map_data.scene_data[i].type + "\" doesn't name a type.");
    }
  std::sort(scene_elements.begin(),scene_elements.end(),SceneElementData::ClickComparison());

  //verify that the click order is the same than the emergence order
  bool same_order = true;
  int i  = 0;
  SceneElementData::EmergenceComparison cmp;
  while(i <= static_cast<int>(scene_elements.size())-2 && same_order)
  {
      same_order = cmp(scene_elements[i], scene_elements[i+1]);
      i++;
  }
  if(!same_order)
      throw invalid_argument("The click order and the emergence order are different.");
}

void MapReader::startSong()
{
  map_data.song->play();
  score = 0;
  last_id_not_clicked = 0;
  last_id_not_displayed = 0;
}

//This function returns the elements which have never been displayed before but which have to be displayed starting from now.
vector<SceneElementData*> MapReader::getNewElements(const sf::Time& time)
{
  vector<SceneElementData*> ret;
  int i = last_id_not_displayed;

  //looking forthe elements to emerge
  while(i < static_cast<int>(scene_elements.size()) && scene_elements[i]->getEmergence() <= time)
    {
      if(scene_elements[i]->hasToEmerge(time))
	{
	  ret.push_back(scene_elements[i]);
	  scene_elements[i]->emerge();
	}
      i++;
    }
  last_id_not_displayed = i;
  return ret;
}

int MapReader::getScore() const
{
    return score;
}

//has to be called each time there is a click
void MapReader::computeScore(const int x, const int y, const sf::Time& time)
{
    if(!scene_elements.empty())
    {
    score += scene_elements[last_id_not_clicked]->computeScore(time,sf::Vector2f(x,y));
    if(last_id_not_clicked <= static_cast<int>(scene_elements.size()) - 2)
       last_id_not_clicked ++;
    }
    else
    {
        score -= MISSED;
    }
}

MapReader::~MapReader()
{
  for( int i = 0; i < static_cast<int>(map_data.scene_data.size()); i++)
    delete scene_elements[i];
}
