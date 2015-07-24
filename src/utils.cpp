#include "utils.hpp"

using namespace std;

unsigned int parseColor(const string& hexString)
{
  stringstream converter(hexString);
  unsigned int color;
  converter >> hex >> color;
  return color;
}
