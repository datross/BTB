#ifndef CONTROLLER
#define CONTROLLER

#include <SFML/Window.hpp>
#include "view.hpp"
#include "mapreader.hpp"
#include <string>


class Controller
{
public :
  Controller(MapReader* reader);
  void update();
  void eventLoop();
 
private : 
  sf::Event event;
  MapReader* reader;
  View view;

};

#endif //CONTROLLER
