#include "utils.hpp"
#include <iostream>

using namespace std;

sf::Color parseColor(const string& hexString)
{
  stringstream converter(hexString);
  unsigned int color;
  converter >> hex >> color;
  
  return sf::Color(color>>24,(color>>16) % 256, (color>>8)%256, color%256);
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
