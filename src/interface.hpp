/*** This file contains the mother class of every big displayable element of the program ***/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>

class InterfaceElement
{
public :
  InterfaceElement();
  void setActivity(const bool active);
  void setVisibility(const bool visible);
  bool isActive() const;
  bool isVisible() const;

  //THESE TWO FUNCTIONS HAVE TO BE REIMPLEMENTED.

  // first update the element
  virtual void update();

  // and then show it
  virtual void show(const sf::View&);

private :
  bool active;
  bool visible;

};

#endif // INTERFACE_H
