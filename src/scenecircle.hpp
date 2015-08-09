/*** This file contains the SceneCircle, which is a graphic circle
 * element.
 * ***/

#ifndef SCENECIRCLE_HPP
#define SCENECIRCLE_HPP

#include "sceneelement.hpp"
#include "scenecircledata.hpp"
#include "utils.hpp"

class SceneCircle : public SceneElement
{
public:
    SceneCircle(sf::RenderWindow * window, const SceneElementData * data);
    ~SceneCircle();

    // prepare the display position
    void prepare(const sf::Time& time);

    // display the sprites
    void show();
private:
    // images
    sf::Image circle_image;
    sf::Texture circle_tex;
    sf::Sprite circle_1, circle_2;

    // positions of both images to display
    sf::Vector2f pos_circle_1, pos_circle_2;

    sf::RenderWindow * window;

    // enables access to SceneCircleData methods
    const SceneCircleData * casted_data;
};

#endif // SCENECIRCLE_HPP

