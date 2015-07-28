#include "gamescene.hpp"

GameScene::GameScene(MapReader * reader, sf::RenderWindow* window)
    : map_reader(reader), window(window)
{

}

GameScene::~GameScene()
{

}

void GameScene::update(sf::Time time)
{
    current_time = time;

    // removing useless elements
    removeUselessElements(&elements);

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
}

void GameScene::show(sf::Rect<int> clip)
{
    if(isVisible())
    {
        elements.show();
    }
}

void GameScene::removeUselessElements(SceneElement* element)
{
    if(element != NULL)
    {
        if(current_time > element->getData()->getEmergence() + element->getData()->getDuration())
        {
            SceneElement * sauv = element->next;
            element->autoRemove();
            removeUselessElements(sauv);
        }
    }
}
