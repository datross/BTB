#include "interface.hpp"

InterfaceElement::InterfaceElement()
{}

void InterfaceElement::setActivity(const bool a_active)
{
    active = a_active;
}

bool InterfaceElement::isActive()
{
    return active;
}

void InterfaceElement::setVisibility(const bool a_visible)
{
    visible = a_visible;
}

bool InterfaceElement::isVisible()
{
    return visible;
}

void InterfaceElement::update()
{

}

void InterfaceElement::show(sf::Rect<int>)
{

}




