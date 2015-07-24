#include "gamescene.hpp"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::update()
{
    std::vector<SceneElement>::iterator it = elements.begin();
    for(; it != elements.end(); it++)
    {
        it->prepare(current_time);
        it->show();
    }
}
