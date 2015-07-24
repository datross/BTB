#ifndef SCENECIRCLE_HPP
#define SCENECIRCLE_HPP

#include "sceneelement.hpp"

class SceneCircle : public SceneElement
{
public:
    SceneCircle();
    ~SceneCircle();

    // initialize the sprites
    void initialize(float time, float duration, float ratio_before_click, int radius, sf::Rect<int> position, sf::Color color);

    // prepare the display position
    virtual void prepare(float time);

    // display the sprites
    virtual void show();
private:
    sf::Image circle_image;
    sf::Texture circle_tex;
    sf::Sprite circle_1, circle_2;

    float click_time, duration, ratio_before_click;

    int radius;

    sf::Rect<int> position;

    sf::Color color;
};

#endif // SCENECIRCLE_HPP

