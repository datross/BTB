#include "gamescene.hpp"

GameScene::GameScene(MapReader * reader, sf::RenderWindow* window)
    : map_reader(reader), window(window)
{
    elements = NULL;
}

GameScene::~GameScene()
{

}

void GameScene::update(sf::Time time)
{
    current_time = time;

    // removing useless elements
    removeUselessElements(elements);

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

            if(elements == NULL)
            {
                elements = circle;
            }
            else
            {
                elements->addElement(circle);
            }
        }
    }

    if(elements != NULL)
    {
        // preparing elements
        elements->prepare(time);
    }
}

void GameScene::show(const sf::View& clip)
{
    if(isVisible())
    {
        if(elements != NULL)
        {
            elements->show(current_time);
        }
    }
}

// recursive function which remove every element which has not to be displayed anymore
void GameScene::removeUselessElements(SceneElement* element)
{
    if(element != NULL)
    {
        // if the element has to be deleted
        if(current_time > element->getData()->getEmergence() + element->getData()->getDuration())
        {
            SceneElement * sauv = element->next;
            bool first = false;

            if(element->previous == NULL)
                first = true; // first of the chain

            element->autoRemove();

            if(first)
                elements = sauv;

            removeUselessElements(sauv);
        }
    }
}
