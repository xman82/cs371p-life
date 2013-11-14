#ifndef LIFE_H
#define LIFE_H
#include <vector>
#include "ConwayCell.h"

template <typename T>
class Life {
  private:
    unsigned rows;
    unsigned columns;
    std::vector< T > grid;
    unsigned popcount;
    unsigned stepcount;
  public:
    Life(unsigned r, unsigned c);
    Life() : rows(0), columns(0), popcount(0), stepcount(0)  {}
    //Life(std::istream& is);
    //void print(std::ostream& = std::cout);
    
    unsigned getNeighbourSum(unsigned);
    void step ();
    void read(std::istream& is = std::cin);
    void print(std::ostream& os = std::cout);
    void kill (unsigned);
    void revive (unsigned);
};

template <class T>
unsigned Life< T >::getNeighbourSum (unsigned idx)
{
  return 2;
}

template <class T>
void Life< T >::step () 
{
  for (unsigned i = 0; i < grid.size(); i++)
  {
    unsigned neighbourhood = getNeighbourSum(i);
    if (neighbourhood == 3)
      revive(i);
    else if (neighbourhood < 2 || neighbourhood > 3)
      kill(i);
  }
  stepcount++;
}

template <class T>
Life<T>::Life(unsigned r, unsigned c): grid(r * c), popcount(0), stepcount(0) {
  rows = r;
  columns = c;
}

template <class T>
void Life< T >::read(istream& is) {
  is >> rows;
  is >> columns;
  grid = vector<T>(rows * columns);
  for (int i = 0; i < rows*columns; i++)
  {
    is >> grid[i];
      if (grid[i].isAlive())
      {
        popcount++;
      }
  }
}

template <class T>
void Life< T >::print(std::ostream& os) {
  os << "Generation = " << stepcount << " Population = " << popcount << "." << std::endl;
  for(unsigned i = 0; i < rows; ++i) {
    for(unsigned j = 0; j < columns; ++j) {
      os<<grid[i*columns + j];
    }
    os<<std::endl;
  }
}

template <class T>
void Life< T >::kill (unsigned i)
{
  popcount--;
  grid[i].die();
}

template <class T>
void Life< T >::revive (unsigned i)
{
  popcount++;
  grid[i].reanimate();
}

#endif /* LIFE_H */
