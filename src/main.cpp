#include "interface.hpp"
#include "json.hpp"
#include "mapdata.hpp"
#include "scenecircledata.hpp"
#include "mapreader.hpp"
#include "controller.hpp"
using namespace std;

int main()
{
  /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
	}*/
  MapData data("maps/first_map.json");
  
  MapReader reader(data);
  cout<<"hey"<<endl;
  Controller control(&reader);
  //control.eventLoop();
  //View view();

    return 0;
}


