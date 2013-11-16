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

void ConwayCell::evalLiveness (Grid& neighbourhood)
{
  unsigned sum = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (neighbourhood.getCell(i,j).isAlive() && !(i == 1 && j == 1))
        sum++;
  if (sum == 3)
    should_live = true;
  else if (sum < 2 || sum > 3)
    should_live = false;
}

void ConwayCell::update()
{
  if (should_live)
    reanimate();
  else
    die();
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
