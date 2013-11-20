#ifndef LIFE_H
#define LIFE_H
#include <vector>
#include <type_traits> // C++0x
#include "Cell.h"

template <typename T>
class Life {
  private:
    unsigned rows;
    unsigned columns;
    Grid grid;
    unsigned popcount;
    unsigned stepcount;
  public:
    void step () 
    {
      for (unsigned i = 0; i < rows; i++)
      {
        for(unsigned j = 0; j < columns; j++)
        {
          Grid neighbourhood(3,3);
          neighbourhood = grid.populateGrid(i-1, j-1, neighbourhood);
          grid.getCell(i,j).evalLiveness(neighbourhood );
        }
      }
      stepcount++;
      popcount = 0;
      for (unsigned i = 0; i < rows; i++)
      {
        for (unsigned j = 0; j < columns; j++)
        {
          grid.getCell(i,j).update();
          if(grid.getCell(i,j).isAlive())
            popcount++;
        }
      }
    }

    Life(unsigned r, unsigned c): grid(r,c), popcount(0), stepcount(0) {
      rows = r;
      columns = c;
      if (std::is_same<T, Cell>::value)
      {
        grid.should_mutate = true;
      }
      else
      {
        grid.should_mutate = false;
      }
    }

    void read(std::istream& is = std::cin) {
      is >> rows;
      is >> columns;
      grid = Grid(rows, columns);
      for (unsigned i = 0; i < rows; i++)
      {
        for(unsigned j = 0; j < columns; j++)
        {
            if (grid.setCell(i,j,is))
              popcount++;
        }
      }
    }

    void print(std::ostream& os = std::cout) {
      os << "Generation = " << stepcount << " Population = " << popcount << "." << std::endl;
      grid.print(os);
      os << endl;
    }
};

#endif /* LIFE_H */
