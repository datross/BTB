#include "scenecircledata.hpp"

using namespace std;

SceneCircleData::SceneCircleData(int circleID, const MapData& map_data) : SceneElementData(circleID,map_data)
{
  //verify whether it's really a circle
  if(map_data.scene_data[circleID].type != "circle")
    throw invalid_argument("You tried to use a \"" + map_data.scene_data[circleID].type + "\" ID when a circle ID is needed.");
}


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


sf::Color SceneCircleData::getColor() const
{
  try
    {
      sf::Color color = parseColor(map_data.scene_data[elementID].specificity["color"]);
      
    }
  catch(const exception& e)
    {
      cerr <<"Error in loading circle no "<<elementID<< " : couldn't find color property"<<endl;
      cerr <<"Json error : "<<e.what()<<endl;
    }
}




