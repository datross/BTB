#ifndef MAP_DATA
#define MAP_DATA

#include "json.hpp"
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

using json = nlohmann::json;

class MapData
{
public :
  MapData(const std::string& file);
  void openSong(const std::string& file);
  ~MapData();

private :
  sf::Music* song; //maybe could be better to use RAII

};

#endif 
