#include "ConwayCell.h"

ConwayCell::ConwayCell () : live(false)
{}

bool ConwayCell::isAlive() const
{
  return live;
}

void ConwayCell::reanimate()
{
  live = true;
}

void ConwayCell::die()
{
  live = false;
}

ostream& operator<<(ostream& os, const ConwayCell& cc) {
  if(cc.isAlive())
    os<< '*';
  else
    os<<'.';
  return os;
}

istream& operator>>(istream& is, ConwayCell& cc) {
  char tmp;
  is>>tmp;
  if(tmp == '*')
    cc.reanimate();
  return is;
}
