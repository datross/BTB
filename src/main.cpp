#include "interface.hpp"
#include "json.hpp"
#include "mapdata.hpp"
#include "scenecircledata.hpp"
#include "mapreader.hpp"
#include "controller.hpp"
using namespace std;

int main()
{
  MapData data("maps/first_map.json");
  MapReader reader(data);

  Controller control(&reader);
  control.eventLoop();

  return 0;
}


