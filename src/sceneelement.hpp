#ifndef SCENEELEMENT_HPP
#define SCENEELEMENT_HPP

#include <SFML/Graphics.hpp>

// Classe abastraite pure, pour encapsuler tous les
// objets graphiques de l'affichage.

class SceneElement
{
public:
    SceneElement();
    virtual ~SceneElement() = 0;

    virtual void show() = 0;
private:

};

#endif // SCENEELEMENT_HPP

