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
    GameScene(MapReader*);
    ~GameScene();

    virtual void update();
private:
    // graphic elements to display
    SceneElement elements;

    // current time
    sf::Time current_time;

    MapReader * map_reader;

    sf::RenderWindow * window;
};

#endif // GAMESCENE_HPP

