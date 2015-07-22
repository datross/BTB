#ifndef INTERFACE_H
#define INTERFACE_H

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
  virtual void update() = 0; 
  virtual void show(SDL_Rect) = 0;

private :
  bool active;
  bool visible;

};

#endif // INTERFACE_H
