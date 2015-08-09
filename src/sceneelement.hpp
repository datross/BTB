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

    virtual void prepare(const sf::Time& time);
    virtual void show();

    // accessor for data
    const SceneElementData * getData();

protected:

    // data storing of the element
    const SceneElementData * data;

    bool visible;
};

#endif // SCENEELEMENT_HPP

