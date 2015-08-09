#include "sceneelement.hpp"

SceneElement::SceneElement()
{

}

void SceneElement::prepare(const sf::Time& time)
{
    visible = data->isVisible(time);
}

void SceneElement::show()
{

}

const SceneElementData * SceneElement::getData()
{
    return data;
}
