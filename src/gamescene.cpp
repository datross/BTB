#include "gamescene.hpp"

GameScene::GameScene(MapReader * reader)
    : map_reader(reader)
{

}

GameScene::~GameScene()
{

}

void GameScene::update()
{
    // looking for new elements
    std::vector<SceneElementData*> new_elements = map_reader->getNewElements();

    // adding new elements to the display chain
    std::string type;
    for(std::vector<SceneElementData*>::iterator it = new_elements.begin(); it != new_elements.end(); it++)
    {
        type = (*it)->getType();

        if(type == "circle")
        {
            SceneCircle * circle = new SceneCircle(window, *it);

        }
    }

    // displaying elements
    elements.prepare(current_time);
    elements.show();
}
