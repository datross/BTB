#include "gamescene.hpp"

using namespace std;

GameScene::GameScene(MapReader * reader, sf::RenderWindow* window)
    : map_reader(reader), window(window)
{

}

GameScene::~GameScene()
{
    // deletes the chain
    if(!elements.empty())
    {
        for(list<SceneElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            delete *it;
        }
    }
}

void GameScene::update(const sf::Time& current_time)
{
    // removing useless elements
    removeUselessElements(current_time);

    // looking for new elements
    std::vector<SceneElementData*> new_elements = map_reader->getNewElements(current_time);

    // adding new elements to the display chain
    std::string type;
    for(std::vector<SceneElementData*>::iterator it = new_elements.begin(); it != new_elements.end(); it++)
    {
        type = (*it)->getType();

        if(type == "circle")
        {
            SceneCircle * circle = new SceneCircle(window, *it);

            elements.push_back(circle);
        }
    }

    if(!elements.empty())
    {
        for(list<SceneElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            (*it)->prepare(current_time);
        }
    }
}

void GameScene::show(const sf::View& clip)
{
    if(isVisible())
    {
        if(!elements.empty())
        {
            for(list<SceneElement*>::reverse_iterator it = elements.rbegin(); it != elements.rend(); ++it)
            {
                (*it)->show();
            }
        }
    }
}

// recursive function which remove every element which has not to be displayed anymore
void GameScene::removeUselessElements(const sf::Time& time)
{
    if(!elements.empty())
    {
        for(list<SceneElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            if((*it)->getData()->isPassed(time))
            {
                delete *it;
                it = elements.erase(it);
            }
        }
    }
}

