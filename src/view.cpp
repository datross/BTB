#include "view.hpp"

View::View()
{
    // création de le fenêtre
    window.create(sf::VideoMode(200, 200), "Bite The Beat v0.0");
}

View::~View()
{

}

void View::setMode(Mode mode)
{
    current_mode = mode;
}
