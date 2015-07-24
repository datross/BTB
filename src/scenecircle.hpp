#ifndef SCENECIRCLE_HPP
#define SCENECIRCLE_HPP

#include "sceneelement.hpp"
#include "utils.hpp"

class SceneCircle : public SceneElement
{
public:
    SceneCircle(sf::RenderWindow& window);
    ~SceneCircle();

    // initialize the sprites
    void initialize(float time, float duration, float ratio_before_click, int radius, sf::Vector2f position, sf::Color color);

    // prepare the display position
    void prepare(float time);

    // display the sprites
    void show();
private:
    // images
    sf::Image circle_image;
    sf::Texture circle_tex;
    sf::Sprite circle_1, circle_2;

    // about time
    float click_time, duration, ratio_before_click;

    int radius;

    sf::Vector2f position;

    sf::Color color;

    sf::Vector2f pos_circle_1, pos_circle_2;
    sf::RenderWindow& window;
};

#endif // SCENECIRCLE_HPP

