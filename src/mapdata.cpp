#include "mapdata.hpp"
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

//parse the Json file.
MapData::MapData(const string& file)
{
  ifstream json_file(file);

  if (!json_file)
    throw runtime_error("Json file loading failed");

  stringstream ss;
  ss << json_file.rdbuf();
  json_file.close();
  string str_json = ss.str();

  try
    {
       json json_map = json::parse(str_json);
       song = new sf::Music;
       openSong(json_map["music_file"]);
       loadSceneData(json_map);
    }
  catch(const exception& e)
    {
      cerr << "Error in the loading of the Json file : "<< e.what()<<endl;
    }
      
}

void MapData::openSong(const string& file)
{
  if(!song->openFromFile(file))
    throw runtime_error("The loading of the music file \"" + file + "\" has failed.");
  
}

void MapData::loadSceneData(const json& json_map)
{
  try
    {
      json json_timeline = json_map["game_timeline"];
      sceneElementInfo info_tmp;
      for(json::iterator it = json_timeline.begin(); it != json_timeline.end(); ++it)
	{
	  
	  //fills info_tmp
	  info_tmp.time = sf::seconds((*it)["time"]);
	  info_tmp.duration = sf::seconds((*it)["duration"]);
	  info_tmp.ratio = (*it)["ratio"];
	  info_tmp.type = (*it)["type"].get<string>();
	  info_tmp.specificity = (*it)["specificity"];
	  sceneData.push_back(info_tmp);
	}
    }
  catch(exception const& e)
    {
      cerr<<"Error :" <<e.what()<<endl;
      cerr<<"It seems that the sceneData loading has failed."<<endl;
    }
 
}

MapData::~MapData()
{
  delete song;
}
