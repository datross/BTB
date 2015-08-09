/*** Main file of the Bite The Beat game.
 * BTB is a graphic rythm game using the SFML library.
 * BTB is under the GNU GENERAL PUBLIC LICENSE version 2.
 * ***/

#include "interface.hpp"
#include "json.hpp"
#include "mapdata.hpp"
#include "scenecircledata.hpp"
#include "mapreader.hpp"
#include "controller.hpp"

using namespace std;

int main()
{
    // creates in a map in memory and load it from a file
    MapData data("maps/first_map.json");

    // creates the object able to read map elements in real time
    MapReader reader(data);

    // creates the controller, in charge of input events and connecting every parts together
    Controller control(&reader);

    // starts the main loop
    control.eventLoop();


    return 0;
}


