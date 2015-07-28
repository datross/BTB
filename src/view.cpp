#include "view.hpp"

View::View()
{
    // création de le fenêtre
    window.create(sf::VideoMode(200, 200), "Bite The Beat v0.0");
}

View::~View()
{

}

void View::show()
{
    window.clear();

    // displaying InterfaceElements...

    window.display();
}
