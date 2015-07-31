#include "utils.hpp"
#include <iostream>

using namespace std;

sf::Color parseColor(const string& hexString)
{
  stringstream converter;
  sf::Uint32 color;
  converter << hex << hexString;
  converter >> color;

  return sf::Color(color>>24,(color>>16) % 256, (color>>8) % 256, color % 256);
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

float distance(const sf::Vector2f& start, const sf::Vector2f& arrival)
{
  return sqrt(pow(arrival.x - start.x,2) + pow(arrival.y - start.y,2));
}

