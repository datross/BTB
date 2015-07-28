#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>

//this class is the mother class of all the class wich can be updated and then displayed
class InterfaceElement
{
public :
  InterfaceElement();
  void setActivity(const bool active);
  void setVisibility(const bool visible);
  bool isActive();
  bool isVisible();

  //THESE TWO FUNCTIONS HAVE TO BE REIMPLEMENTED.
  virtual void update();
  virtual void show(sf::Rect<int>);

private :
  bool active;
  bool visible;

};

#endif // INTERFACE_H
