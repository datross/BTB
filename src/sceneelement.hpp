#ifndef SCENEELEMENT_HPP
#define SCENEELEMENT_HPP

#include <SFML/Graphics.hpp>

// Pure abstract class, encapsulating
// every displayable scene object.

class SceneElement
{
public:
    SceneElement();
    virtual ~SceneElement() = 0;

    virtual void prepare(float time) = 0;
    virtual void show() = 0;
private:

};

#endif // SCENEELEMENT_HPP

