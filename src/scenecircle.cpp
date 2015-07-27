#include "scenecircle.hpp"


SceneCircle::SceneCircle(sf::RenderWindow& window)
    : window(window), data(data)
{
    // create image, texture and sprites
    circle_image.create(2 * data, 2 * radius, sf::Color(0,0,0,0));

    // dessin du disque
    for(unsigned int x = 0; x != 2 * radius; x++)
    {
        for(unsigned int y = 0; y != 2 * radius; y++)
        {
            if(distance(x,y,radius,radius) <= radius)
            {
                circle_image.setPixel(x,y,color);
            }
        }
    }

    circle_tex.loadFromImage(circle_image);
    circle_1.setTexture(circle_tex, true);
    circle_2.setTexture(circle_tex, true);
}

SceneCircle::~SceneCircle()
{

}

void SceneCircle::prepare(float time)
{
    // calculation of both positions
    if(time < click_time) // before click time
    {
        pos_circle_1.x = position.x - 2 * radius + static_cast<int>(static_cast<float>(radius) * (time - (click_time - duration * ratio_before_click)) / (duration * ratio_before_click));
        pos_circle_1.y = position.y - radius;
        pos_circle_2.x = position.x + (position.x - pos_circle_1.x) - 2 * radius;
        pos_circle_2.y = pos_circle_1.y;
    }
    else // after click time
    {
        pos_circle_1.x = position.x - radius;
        pos_circle_1.y = position.y - radius;
        pos_circle_2.x = pos_circle_1.x;
        pos_circle_2.y = pos_circle_1.x;
    }

    circle_1.setPosition(pos_circle_1);
    circle_2.setPosition(pos_circle_2);

    // call of the next element
    if(next != NULL)
    {
        next->prepare(time);
    }
}

void SceneCircle::show()
{
    window.draw(circle_1);
    window.draw(circle_2);

    // call of the next element
    if(next != NULL)
    {
        next->show();
    }
}
