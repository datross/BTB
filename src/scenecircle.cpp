#include "scenecircle.hpp"


SceneCircle::SceneCircle(sf::RenderWindow * window, SceneElementData * a_data)
    : window(window)
{
    data = a_data;
    casted_data = dynamic_cast<SceneCircleData*>(data);

    // create image, texture and sprites
    circle_image.create(2 * casted_data->getRadius(), 2 * casted_data->getRadius(), sf::Color(255,0,0,0));

    // dessin du disque
    for(unsigned int x = 0; x != 2 * casted_data->getRadius(); x++)
    {
        for(unsigned int y = 0; y != 2 * casted_data->getRadius(); y++)
        {
            if(/*distance(x,y,casted_data->getRadius(),casted_data->getRadius()) <= casted_data->getRadius()*/true)
            {
                circle_image.setPixel(x,y,casted_data->getColor());
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

void SceneCircle::prepare(sf::Time time)
{
    if(time > casted_data->getEmergence())
    {
        // calculation of both positions
        if(time < casted_data->getClickTime()) // before click time
        {
            pos_circle_1.x = casted_data->getPosition().x - 2 * casted_data->getRadius() + static_cast<int>(static_cast<float>(casted_data->getRadius()) * (time.asSeconds() - (casted_data->getClickTime().asSeconds() - casted_data->getDuration().asSeconds() * casted_data->getRatio())) / (casted_data->getDuration().asSeconds() * casted_data->getRatio()));
            pos_circle_1.y = casted_data->getPosition().y - casted_data->getRadius();
            pos_circle_2.x = casted_data->getPosition().x + (casted_data->getPosition().x - pos_circle_1.x) - 2 * casted_data->getRadius();
            pos_circle_2.y = pos_circle_1.y;
        }
        else // after click time
        {
            pos_circle_1.x = casted_data->getPosition().x - casted_data->getRadius();
            pos_circle_1.y = casted_data->getPosition().y - casted_data->getRadius();
            pos_circle_2.x = pos_circle_1.x;
            pos_circle_2.y = pos_circle_1.x;
        }

        circle_1.setPosition(0.,0.);
        circle_2.setPosition(pos_circle_2);
    }

    // call of the next element
    if(next != NULL)
    {
        next->prepare(time);
    }
}

void SceneCircle::show(sf::Time time)
{
    if(casted_data->getEmergence() < time)
    {
        window->draw(circle_1);
        window->draw(circle_2);
    }

    // call of the next element
    if(next != NULL)
    {
        next->show(time);
    }
}
