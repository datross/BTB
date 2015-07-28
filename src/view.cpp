#include "view.hpp"
#include <iostream>

using namespace std;
View::View()
{
  // création de le fenêtre
  window = new sf::RenderWindow();
  window->create(sf::VideoMode(200, 200), "Bite The Beat v0.0");
}

View::~View()
{
  delete window;
}

void View::show()
{
  window->clear();

  // displaying InterfaceElements...

  window->display();
}
