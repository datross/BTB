/*** This file contains util functions which can be used everwhere in the project ***/
#include <string>
#include <sstream>
#include <cmath>
#include <SFML/Graphics.hpp>

// converts hexadecimal string to sf::Color
sf::Color parseColor(const std::string& hexString);

// computes the distance between to points
float distance(int x1, int y1, int x2, int y2);
float distance(const sf::Vector2f& , const sf::Vector2f&);
