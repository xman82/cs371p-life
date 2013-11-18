#include "FredkinCell.h"
#include "Cell.h"

void FredkinCell::evalLiveness(Grid& neighbourhood)
{
  unsigned sum = 0;
  unsigned indices[4][2] = {{0,1}, {1,0}, {1,2}, {2,1}};
  for (int i = 0; i < 4; i++)
  {
      unsigned row = indices[i][0];
      unsigned col = indices[i][1];
      if (neighbourhood.getCell(row,col).isAlive())
          ++sum;
  }
  if(sum == 1 || sum == 3)
    should_live = true;
  else
    should_live = false;
}
