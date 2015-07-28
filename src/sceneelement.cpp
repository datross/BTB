#include "sceneelement.hpp"

SceneElement::SceneElement()
{

}

void SceneElement::prepare(sf::Time time)
{

}

void SceneElement::show()
{

}

SceneElementData * SceneElement::getData()
{
    return data;
}

void SceneElement::addElement(SceneElement * element)
{
    // sorting by click time in the chain

    if(data->getClickTime() >= element->getData()->getClickTime())
    {
        element->next = this;
        if(previous == NULL)
        {
            previous = element;
            element->previous = NULL;
        }
        else
        {
            element->previous = previous;
            previous->next = element;
            previous = element;
        }
    }
    else
    {
        if(next == NULL)
        {
            next = element;
            element->previous = this;
            element->next = NULL;
        }
        else
        {
            next->addElement(element);
        }
    }
}

void SceneElement::autoRemove()
{
    // detach from the chain

    if(next == NULL && previous == NULL)
    {
        // nothing to do
    }
    else if(next == NULL)
    {
        previous->next = NULL;
    }
    else if(previous = NULL)
    {
        next->previous = NULL;
    }
    else
    {
        next->previous = previous;
        previous->next = next;
    }

    // delete itself
    delete this;
}
