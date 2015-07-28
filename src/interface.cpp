#include "interface.hpp"

InterfaceElement::InterfaceElement()
{}

void InterfaceElement::setActivity(const bool a_active)
{
    active = a_active;
}

bool InterfaceElement::isActive() const
{
    return active;
}

void InterfaceElement::setVisibility(const bool a_visible)
{
    visible = a_visible;
}

bool InterfaceElement::isVisible() const
{
    return visible;
}

void InterfaceElement::update()
{

}

void InterfaceElement::show(const sf::View& view)
{

}




