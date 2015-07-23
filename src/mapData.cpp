#include "mapData.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

MapData::MapData(const string& file)
{
  ifstream json_file(file);
  if (!json_file)
    throw runtime_error("Json file loading failed");
  stringstream ss;
  ss << json_file.rdbuf();
  string str_json = ss.str();
  json json_map = json::parse(str_json);
  
  cout<<json_map["music_file"]<<endl;
  song = new sf::Music;
  openSong("music/1vs0_JuniorGroove.ogg");
  song->play();
}

void MapData::openSong(const string& file)
{
  cout<<file<<endl;
  cout<<song->openFromFile(file)<<endl;
  if(!song->openFromFile(file))
    throw runtime_error("The loading of the music file " + file + "has failed.");
}

MapData::~MapData()
{
  delete song;
}
