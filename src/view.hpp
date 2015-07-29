#ifndef VIEW_HPP
#define VIEW_HPP

#include "gamescene.hpp"
#include "timeviewer.hpp"
#include <vector>

class View
{
public:
    View(MapReader*);
    ~View();

    void show();

    // fenêtre, il faut appeler "create" après dans le constructeur
    sf::RenderWindow* window;

private:

    GameScene * game_scene;
  TimeViewer* tv;
  sf::Font font;

    MapReader * map_reader;
};

#endif // VIEW_HPP

