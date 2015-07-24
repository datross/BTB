#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include <vector>
#include "interface.hpp"
#include "sceneelement.hpp"

class GameScene : public InterfaceElement
{
public:
    GameScene();
    ~GameScene();

    virtual void update();
private:
    // graphic elements to display
    std::vector<SceneElement> elements;

    // current time
    float current_time;
};

#endif // GAMESCENE_HPP

