#include "scenecircle.hpp"

SceneCircle::SceneCircle()
{

}

SceneCircle::~SceneCircle()
{

}

void SceneCircle::initialize(float time, float a_duration, float a_ratio_before_click, int a_radius, sf::Rect<int> a_position, sf::Color a_color)
{
    click_time = time;
    duration = a_duration;
    ratio_before_click = a_ratio_before_click;
    radius = a_radius;
    position = a_position;
    color = a_color;

    // create image, texture and sprites
    circle_image.create(2 * radius, 2 * radius, sf::Color(0,0,0,0));

    circle_tex.loadFromImage(circle_image);
    circle_1.setTexture(circle_tex, true);
    circle_2.setTexture(circle_tex, true);
}
