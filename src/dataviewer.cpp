#include "dataviewer.hpp"

using namespace std;

string timeToString(sf::Time time)
{
    int ms = time.asMilliseconds();
    int sec = ms / 1000;
    int minutes = sec / 60;
    sec %= 60;

    ostringstream convert;
    convert<<minutes<<"' "<<sec<<"'' "<<ms%1000;
    return convert.str();


}

string scoreToString(int score)
{
  ostringstream convert;
  convert<<score;
  return convert.str();
}

DataViewer::DataViewer(sf::RenderWindow* window) : window(window)
{

}


void DataViewer::show(const sf::View& sf_view)
{
    const sf::View& previous_view = window->getView();
    window->setView(sf_view);
    window->draw(*this);
    window->setView(previous_view);
}

void DataViewer::setTime(const sf::Time& time)
{
    setString(timeToString(time));
}

void DataViewer::setScore(int score)
{
    setString(scoreToString(score));
}
