/*** This file contains the class mapData which contains raw data about the maps ***/
#ifndef MAP_DATA
#define MAP_DATA

#include "json.hpp"
#include "utils.hpp"
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

using json = nlohmann::json;

//this structure gives informations about a screenElement
typedef struct sceneElementInfo
{
  double duration; 
  double time;//the moment at which you must click
  std::string type;
  json specificity;
} sceneElementInfo;

class MapData
{
public :
  MapData(const std::string& file);
  sf::Music* song; //maybe could be better to use RAII
  std::vector<sceneElementInfo> sceneData;

  ~MapData();

private :
  void openSong(const std::string& file);
  void loadSceneData(const json& json_map);
};

#endif 
