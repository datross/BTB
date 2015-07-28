#include "view.hpp"
#include <iostream>

using namespace std;
View::View()
{
    // création de le fenêtre
 
    window->create(sf::VideoMode(200, 200), "Bite The Beat v0.0");
 cout<<"hedy"<<endl;
}

View::~View()
{

}

void View::show()
{
    window->clear();

    // displaying InterfaceElements...

    window->display();
}
