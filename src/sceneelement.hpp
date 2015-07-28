#ifndef SCENEELEMENT_HPP
#define SCENEELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "sceneelementdata.hpp"

// Pure abstract class, encapsulating
// every displayable scene object.

class SceneElement
{
public:
    SceneElement();

    virtual void prepare(sf::Time time);
    virtual void show(sf::Time time);

    // previous and next SceneElement in the list, it can be "NULL".
    SceneElement * previous, * next;

    void addElement(SceneElement*);
    void autoRemove();

    // accessor for data
    SceneElementData * getData();
protected:

    // data storing of the element
    SceneElementData * data;
};

#endif // SCENEELEMENT_HPP

