#include "controller.hpp"

using namespace std;

Controller::Controller(MapReader* reader) : reader(reader),view(reader)
{
    startSong();
}

void Controller::update()
{

}

void Controller::eventLoop()
{
  while (view.window->isOpen())
    {
      loop_time = clock.getElapsedTime();
      sf::Event event;
      while (view.window->pollEvent(event))
        {
	  if (event.type == sf::Event::Closed)
	    view.window->close();
      if(event.type == sf::Event::MouseButtonPressed)
        {
          reader->computeScore(event.mouseButton.x,event.mouseButton.y, loop_time);
        }

        }
      view.show(loop_time);
      }
}


void Controller::startSong()
{
    clock.restart();
    reader->startSong();
}

