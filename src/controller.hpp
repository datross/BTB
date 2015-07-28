#ifndef CONTROLLER
#define CONTROLLER

#include <SFML/Window.hpp>
#include "view.hpp"
#include "mapreader.hpp"
#include <string>


class Controller
{
public :
  Controller(MapReader& file);
  void update();
  void eventLoop();
 
private : 
  sf::Event event;
  MapReader& reader;
  View view;

};

#endif //CONTROLLER
