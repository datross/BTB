#ifndef VIEW_HPP
#define VIEW_HPP

#include "gamescene.hpp"

class View
{
public:
    View();
    ~View();

    void show();

    // fenêtre, il faut appeler "create" après dans le constructeur
    sf::RenderWindow window;

private:
};

#endif // VIEW_HPP

