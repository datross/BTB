#ifndef SCENEELEMENT_HPP
#define SCENEELEMENT_HPP

#include <SFML/Graphics.hpp>

// Abstract class, encapsulating
// every displayable scene object.

class SceneElement
{
public:
    SceneElement();
    ~SceneElement();

    virtual void prepare(float time) = 0;
    virtual void show() = 0;
private:

};

#endif // SCENEELEMENT_HPP

