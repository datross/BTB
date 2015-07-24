#ifndef MAP_DATA
#define MAP_DATA

#include "json.hpp"
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

using json = nlohmann::json;

//this structure gives informations about a screenElement
typedef struct sceneElementInfo
{
  double duration; 
  double time;
  std::string type;
} sceneElementInfo;

class MapData
{
public :
  MapData(const std::string& file);
  void openSong(const std::string& file);
  void loadSceneData(json json_map);
  ~MapData();

private :
  sf::Music* song; //maybe could be better to use RAII
  std::vector<sceneElementInfo> sceneData;

};

#endif 
