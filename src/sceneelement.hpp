#ifndef SCENEELEMENT_HPP
#define SCENEELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <stdexcept>

// Pure abstract class, encapsulating
// every displayable scene object.

class SceneElement
{
public:
    SceneElement();

    virtual void prepare(float time) = 0;
    virtual void show() = 0;

    // previous and next SceneElement in the list, it can be "NULL".
    SceneElement * previous, * next;
private:
};

#endif // SCENEELEMENT_HPP

