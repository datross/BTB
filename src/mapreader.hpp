#ifndef MAP_READER
#define MAP_READER

#include <vector>
#include "sceneelementdata.hpp"
#include "scenecircledata.hpp"
#include "mapdata.hpp"

#include <SFML/System.hpp>

class MapReader
{
  MapReader(const MapData& map_data);
  void startSong();

private :
  std::vector<SceneElementData* > scene_elements;
};

#endif //MAP_READER
