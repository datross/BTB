#include "scenecircledata.hpp"

using namespace std;

SceneCircleData::SceneCircleData(int circleID, const MapData& map_data) : SceneElementData(circleID,map_data)
{
  //verifies whether it's really a circle
  if(map_data.scene_data[circleID].type != "circle")
    throw invalid_argument("You tried to use a \"" + map_data.scene_data[circleID].type + "\" ID when a circle ID is needed.");
}


int SceneCircleData::getScore(const sf::Time& click_moment, const sf::Vector2f& click_position) const
{
  if(distance(click_position,getPosition()) <= static_cast<float>(getRadius()))
    {
      if(click_moment >= getClickTime())//Careful : position DivisionBy Zero
	return static_cast<int>( 100.0 * (static_cast<float>((getEmergence() + getDuration() - click_moment()).asMilliseconds()) / static_cast<float>((getDuration()* (1 - getRatio())).asMilliseconds())));
      else 
	return static_cast<int>(100.0 * (static_cast<float>((click_moment - getEmergence()).asMilliseconds()) / static_cast<float>((getDuration()*  getRatio()).asMilliseconds())));
    }
  else
    return -1;
}

//returns the radius of the circle
int SceneCircleData::getRadius() const
{
  int radius = 0;
  try
    {
      radius = map_data.scene_data[elementID].specificity["radius"];
    }
  catch(const exception& e)
    {
      cerr <<"Error in loading circle no "<<elementID<< " : couldn't find radius property"<<endl;
      cerr <<"Json error : "<<e.what()<<endl;
    }
  return radius;
}

//returns the color of the circle
sf::Color SceneCircleData::getColor() const
{
  sf::Color color;
  try
    {
      color = parseColor(map_data.scene_data[elementID].specificity["color"]);
      
    }
  catch(const exception& e)
    {
      cerr <<"Error in loading circle no "<<elementID<< " : couldn't find color property"<<endl;
      cerr <<"Json error : "<<e.what()<<endl;
    }
  return color;
}


//return the position of the circle
sf::Vector2f SceneCircleData::getPosition() const
{
  sf::Vector2f position;
    try
    {
      position = parsePosition(map_data.scene_data[elementID].specificity["position"]);
      
    }
  catch(const exception& e)
    {
      cerr <<"Error in loading circle no "<<elementID<< " : couldn't find position property"<<endl;
      cerr <<"Json error : "<<e.what()<<endl;
    }
}




