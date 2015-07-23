#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include <queue>
#include "interface.hpp"
#include "sceneelement.hpp"

class GameScene : public InterfaceElement
{
public:
    GameScene();
    ~GameScene();

    virtual void update();
private:
    std::queue<SceneElement> circles;
};

#endif // GAMESCENE_HPP

