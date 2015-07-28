#ifndef TIME_VIEWER
#define TIME_VIEWER
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "interface.hpp"
#include <string>
#include <sstream>

std::string timeToString(sf::Time time);

class TimeViewer : public sf::Text, public InterfaceElement
{
public :
  TimeViewer(sf::RenderWindow* window);
  void show(const sf::View& sf_view);
  void setTime(const sf::Time& time);
private :
  sf::RenderWindow* window;
};
#endif
