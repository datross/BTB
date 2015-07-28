#include "view.hpp"
#include <iostream>

using namespace std;
View::View(MapReader* map_reader)
    : map_reader(map_reader)
{
  // création de le fenêtre
  window = new sf::RenderWindow(sf::VideoMode(500, 500), "Bite The Beat v0.0");

  game_scene = new GameScene(map_reader, window);
  game_scene->setActivity(true);
  game_scene->setVisibility(true);
}

View::~View()
{
  delete window;
}

void View::show()
{
    sf::Rect<int> r(0,0,0,0);

  window->clear();

  // displaying InterfaceElements...
  game_scene->update(map_reader->getTime());

  game_scene->show(r);

  window->display();
}
