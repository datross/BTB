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
  double time;//the moment at which you must click
  std::string type;
  //maybe could be better to add a json object in sceneElementInfo and let each scene element parse its own Json object. Could allow much more flexibility about the JSon file.
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
