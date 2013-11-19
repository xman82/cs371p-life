#ifndef Cell_H
#define Cell_H

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"

class Cell : public Handle<AbstractCell> {
  bool isConway;
  bool should_mutate;
  public:
    bool isAlive () const { return get()->isAlive(); }
    void die(){ get()->die(); }
    void reanimate (){ get()->reanimate(); }
    void update(){ 
      get()->update();
      if (get()->getAge() == 2 && get()->isAlive() && !isConway)
      {
        isConway = true;
        mutate();
      }
    }
    void evalLiveness (Grid& neighbourhood){ get()->evalLiveness(neighbourhood); }
    void printCell(std::ostream& os = std::cout)
    {
      get()->print(os);
    }

    void mutate () {
      _p = new ConwayCell(true);
    }

    Cell (char rep, bool mut) : Handle(0), should_mutate(mut)
    {
      if(rep == '.' || rep == '*')
      {
        _p = new ConwayCell(rep);
        isConway = true;
      }
      else if(rep == '-' || rep == '+' ||  isdigit(rep))
      {
        isConway=false;
        _p = new FredkinCell(rep);
      }
    }

    Cell() : Handle(0) , isConway(false) {}
    Handle& operator= (AbstractCell* p) {
      _p = p;
      return *this;}
};

class Grid {
  unsigned rows;
  unsigned columns;
  vector<Cell> content;
  public:
  bool should_mutate;
  Grid (int row, int col) : rows(row), columns(col), content(rows*columns) {}

  Grid& populateGrid(int row, int col, Grid& g)
  {
    for(unsigned i = 0; i < g.rows; ++i)
    {
      for(unsigned j = 0; j < g.columns; ++j)
      {
        if(row < 0 || col < 0 || row == rows - 2 || col == columns - 2)
          g.content[i*g.columns + j] = new ConwayCell();
        else
          g.content[i*g.columns + j] = content[(row + i) * columns + col + j];
      }
    }
    return g;
  }

  void print(std::ostream& os = std::cout)
  {
      for(unsigned i = 0; i < rows; ++i) {
        for(unsigned j = 0; j < columns; ++j) {
          content[i*columns + j].printCell(os);
        }
        os<<std::endl;
      }
  }

  bool setCell(int row, int col, std::istream& is)
  {
    char rep;
    is >> rep;
    content[row*columns + col] = Cell(rep,should_mutate);
    return content[row*columns + col].isAlive();
  }

  Cell& getCell(int row, int col)
  {
    return content[row*columns + col];
  }
};
#endif
