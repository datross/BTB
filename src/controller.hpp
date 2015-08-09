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
  void startSong();
 
private : 
  sf::Event event;
  MapReader* reader;
  View view;

  sf::Clock clock;

  // time at the beginning of the loop
  sf::Time loop_time;
};

#endif //CONTROLLER
