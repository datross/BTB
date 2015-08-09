#ifndef MAP_READER
#define MAP_READER

#include <vector>
#include <stdexcept>
#include "sceneelementdata.hpp"
#include "scenecircledata.hpp"
#include "mapdata.hpp"
#include <algorithm>


#include <SFML/System.hpp>

class MapReader
{
public:
  MapReader(const MapData& map_data);
  ~MapReader();
  void startSong();
  std::vector<SceneElementData*> getNewElements(const sf::Time&); //can't be const because last_id_not_displayed is modified.

private :
  std::vector<SceneElementData*> scene_elements;//this vector is sorted by emergence order.
  const MapData& map_data;
  int last_id_not_displayed; //this id avoids to  browse all the scene_elements vector when getNewElements is called.
};

#endif //MAP_READER
