/*** This file contains the InterfaceElement class relating
 * to the game display. ***/

#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include <vector>
#include "interface.hpp"
#include "sceneelement.hpp"
#include "scenecircle.hpp"
#include "mapreader.hpp"

class GameScene : public InterfaceElement
{
public:
    GameScene(MapReader*, sf::RenderWindow*);
    ~GameScene();

    // computes circles' positions, and update the SceneElement chain
    void update(sf::Time);

    // display the game
    void show(const sf::View&); // /!\ To do : make the parameter usefull

private:
    // remove useless elements
    void removeUselessElements(SceneElement*);

    // graphic elements to display
    SceneElement * elements;

    // current time
    sf::Time current_time;

    MapReader * map_reader;

    sf::RenderWindow * window;
};

#endif // GAMESCENE_HPP

