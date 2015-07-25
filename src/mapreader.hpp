#ifndef MAP_READER
#define MAP_READER

#include <vector>
#include <stdexcept>
#include "sceneelementdata.hpp"
#include "scenecircledata.hpp"
#include "mapdata.hpp"

#include <SFML/System.hpp>

class MapReader
{
public:
  MapReader(const MapData& map_data);
  ~MapReader();
  void startSong();
  const SceneElementData& getSceneElementData(int id);

private :
  std::vector<SceneElementData* > scene_elements;
  const MapData& map_data;
  sf::Clock clock;
  std::vector<int> ids_displayed;
};

#endif //MAP_READER
