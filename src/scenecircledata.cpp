#include "scenecircledata.hpp"

using namespace std;

SceneCircleData::SceneCircleData(int circleID, const MapData& map_data) : SceneElementData(circleID,map_data)
{
  //verify whether it's really a circle
  if(map_data.sceneData[circleID].type != "circle")
    throw invalid_argument("A circle ID is needed.");
}

int SceneCircleData::getRadius()
{
  int radius = 0;
  try
    {
      radius = map_data.sceneData[elementID].specificity["radius"];
    }
  catch(const exception& e)
    {
      cerr <<"Error in loading circle no "<<elementID<< " : couldn't find radius property"<<endl;
      cerr <<"Json error : "<<e.what()<<endl;
    }
  return radius;
}


sf::Color SceneCircleData::getColor()
{
  try
    {
      sf::Color color = parseColor(map_data.sceneData[elementID].specificity["color"]);
      
    }
  catch(const exception& e)
    {
      cerr <<"Error in loading circle no "<<elementID<< " : couldn't find color property"<<endl;
      cerr <<"Json error : "<<e.what()<<endl;
    }
}




