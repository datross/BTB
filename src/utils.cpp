#include "utils.hpp"

using namespace std;

unsigned int parseColor(const string& hexString)
{
  stringstream converter(hexString);
  unsigned int color;
  converter >> hex >> color;
  return color;
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
