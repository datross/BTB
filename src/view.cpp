#include "view.hpp"
#include <iostream>
#include <string>

using namespace std;

View::View(MapReader* map_reader)
  : map_reader(map_reader)
{
  // création de le fenêtre
  window = new sf::RenderWindow(sf::VideoMode(500, 500), "Bite The Beat v0.0");

  game_scene = new GameScene(map_reader, window);
  game_scene->setActivity(true);
  game_scene->setVisibility(true);

  sf::Font font;
  font.loadFromFile("font/augusta.ttf");
  /*tv = new TimeViewer(window);
  tv->setFont(font);
  tv->setCharacterSize(24);
  tv->setPosition(0,0);
  tv->setString("igyud");*/
}

View::~View()
{
  delete window;
  delete game_scene;
  delete tv;
}

void View::show()
{

  sf::View sf_view = window->getView();

  window->clear();

  sf::Font font;
  font.loadFromFile("font/augusta.ttf");
  TimeViewer text(window);
  text.setTime(map_reader->getTime());
  text.setFont(font);
  text.setColor(sf::Color::Red);
  text.setCharacterSize(24);
  text.setPosition(0,0);
  text.show(sf_view);
  
  //tv->show(sf_view);
  // displaying InterfaceElements...
  game_scene->update(map_reader->getTime());

  game_scene->show(sf_view);

  window->display();
}
