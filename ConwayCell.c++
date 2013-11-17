#include "ConwayCell.h"
#include "Cell.h"

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
  if (sum == 3 || (live && sum == 2 ))
    should_live = true;
  else
    should_live = false;
}

void ConwayCell::update()
{
  if (should_live)
    reanimate();
  else
    die();
}
