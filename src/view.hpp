#ifndef VIEW_HPP
#define VIEW_HPP

#include "gamescene.hpp"
#include <vector>

class View
{
public:
    View();
    ~View();

    void show();

    // fenêtre, il faut appeler "create" après dans le constructeur
    sf::RenderWindow* window;

private:
    std::vector<InterfaceElement*> elements;
};

#endif // VIEW_HPP

