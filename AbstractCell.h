#ifndef ABSTRACT_CELL_H
#define ABSTRACT_CELL_H
#include <vector>

using namespace std;

class Grid;
class AbstractCell {
  bool live;
  bool should_live;
  public:
    /** Is this cell currently alive ? */
    AbstractCell();
    virtual bool isAlive () const;
    virtual void die();
    virtual void reanimate ();
    virtual void update();
    virtual void evalLiveness (Grid& neighbourhood);
};

class Grid {
  vector<AbstractCell> content;
  unsigned rows;
  unsigned columns;
  public:
  Grid (int row, int col) : rows(row), columns(col) {}
  AbstractCell& getCell(int row, int col)
  {
    return content[row*columns + col];
  }
};


#endif
