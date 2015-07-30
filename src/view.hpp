/*** This file contains the View part of the MVC architecture.
***/

#ifndef VIEW_HPP
#define VIEW_HPP

#include "gamescene.hpp"
#include "dataviewer.hpp"
#include <vector>

class View
{
public:
    View(MapReader*);
    ~View();

    // displays the program
    void show();

    // window on which the program is displayed
    sf::RenderWindow* window;

private:

    // InterfaceElements to display
    GameScene * game_scene;
    DataViewer* tv;

    sf::Font font;

    MapReader * map_reader;
};

#endif // VIEW_HPP

