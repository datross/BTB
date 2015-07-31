#include "sceneelement.hpp"

SceneElement::SceneElement()
{
    next = NULL;
    previous = NULL;
}

void SceneElement::prepare(sf::Time time)
{

}

void SceneElement::show(sf::Time time)
{

}

const SceneElementData * SceneElement::getData()
{
    return data;
}

void SceneElement::addElement(SceneElement * element)
{
    // sorting by click time in the chain

    // if it has to be inserted just before this element
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
    else // otherwise it will be inserted later in the chain
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

    if(next != NULL || previous != NULL)
    {
        if(next == NULL)
        {
            previous->next = NULL;
        }
        else if(previous == NULL)
        {
            next->previous = NULL;
        }
        else
        {
            next->previous = previous;
            previous->next = next;
        }
    }

    // deletes itself
    delete this;
}
