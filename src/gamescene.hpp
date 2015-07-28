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

    void update(sf::Time);
    void show(const sf::View&);
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

