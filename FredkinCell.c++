#include "FredkinCell.h"
#include "Cell.h"

void FredkinCell::evalLiveness(Grid& neighbourhood)
{
  unsigned sum = 0;
  if(neighbourhood.getCell(0,1).isAlive())
    ++sum;
  if(neighbourhood.getCell(1,0).isAlive())
    ++sum;
  if(neighbourhood.getCell(1,2).isAlive())
    ++sum;
  if(neighbourhood.getCell(2,1).isAlive())
    ++sum;
  if(sum == 1 || sum == 3)
    should_live = true;
  else
    should_live = false;
}
