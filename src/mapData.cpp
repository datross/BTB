#include "mapData.hpp"
#include <fstream>
#include <sstream>

using namespace std;

MapData::MapData(string file)
{
  ifstream json_file(file);
  if (!json_file)
    throw runtime_error("Json file loading failed");
  stringstream ss;
  ss << json_file.rdbuf();
  string str_json = ss.str();
  json json_map = json::parse(str_json);
  cout<<json_map["music_file"]<<endl;
  
}
