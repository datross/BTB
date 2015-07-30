/*** This file contains the mother class of every graphic
 * element whiwh is part of the game.
***/

#ifndef SCENEELEMENT_HPP
#define SCENEELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "sceneelementdata.hpp"

class SceneElement
{
public:
    SceneElement();

    virtual void prepare(sf::Time time);
    virtual void show(sf::Time time);

    // previous and next SceneElement in the chain, it can be "NULL".
    SceneElement * previous, * next;

    // insert an element in the chain, by clicTime order
    void addElement(SceneElement*);

    // removes and deleting itself from the chain and the memory
    void autoRemove();

    // accessor for data
    SceneElementData * getData();
protected:

    // data storing of the element
    SceneElementData * data;
};

#endif // SCENEELEMENT_HPP

