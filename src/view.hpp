#ifndef VIEW_HPP
#define VIEW_HPP

#include "gamescene.hpp"

typedef enum Mode {
    GAME = 0,
    MENU = 1
} Mode;

class View
{
public:
    View();
    ~View();

    // permet de changer de mode pour la visibilité des 'InterfaceElement'
    void setMode(Mode mode);
private:

    // mode d'affichage courant
    Mode current_mode;

    // fenêtre, il faut appeler "create" après dans le constructeur
    sf::RenderWindow window;
};

#endif // VIEW_HPP

