#ifndef Cell_H
#define Cell_H

#include "AbstractCell.h"
#include <cassert>
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
      if (get()->getAge() >= 2 && get()->isAlive() && !isConway && should_mutate)
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

  /** Changes a conway to a fredkin
   */
    void mutate () {
      assert(false);
      Handle::operator=(Handle(new ConwayCell(true)));
    }

  /** Creates a conway or fredkin cell based on the character given
   * @param rep The character representation
   * @param mut whether the cell should mutate during an update if it's a fredkin
   */
    Cell (char rep, bool mut = false) : Handle(0), isConway(false), should_mutate(mut)
    {
      if(rep == '.' || rep == '*')
      {
          Handle::operator=(Handle(new ConwayCell(rep)));
          isConway = true;
      }
      else if(rep == '-' || rep == '+' ||  isdigit(rep))
      {
          Handle::operator=(Handle(new FredkinCell(rep)));
          isConway=false;
      }
    }

  /** Creates the Cell with reasonable defaults. The Grid shouldn't be used with these until the values are changed
   */
    Cell() : Handle(0), isConway(false), should_mutate(false) {}
};

class Grid {
  unsigned rows;
  unsigned columns;
  vector<Cell> content;
  public:
  bool should_mutate;
  /** Creates Grid with the requested dimensions
   * @param row is the desired number of rows
   * @param col is the desired number of columns
   */
  Grid (int row, int col) : rows(row), columns(col), content(rows*columns), should_mutate(false) {}


  /** fills the grid with Cells
   * @param row is the number of rows
   * @param col is the number of columns
   * @param g is the grid to be filled
   * @returns filled grid
   */
  Grid& populateGrid(int row, int col, Grid& g) const
  {
    for(unsigned i = 0; i < g.rows; ++i)
    {
      for(unsigned j = 0; j < g.columns; ++j)
      {
        if (row < 0 || col < 0 || (unsigned) row >= rows - 2 || (unsigned) col >= columns - 2)
          g.content[i*g.columns + j] = Cell('.', false);
        else
          g.content[i*g.columns + j] = content[(row + i) * columns + col + j];
      }
    }
    return g;
  }

  /**
   * prints the grid
   */
  void print(std::ostream& os = std::cout)
  {
      for(unsigned i = 0; i < rows; ++i) {
        for(unsigned j = 0; j < columns; ++j) {
          content[i*columns + j].printCell(os);
        }
        os<<std::endl;
      }
  }

  /**
   * sets corresponding Cell type based on char representation
   * @row is the row location of the cell
   * @col is the column location of the cell
   * @is contains the character representation of the cell
   * @returns the liveness of Cell
   */
  bool setCell(int row, int col, std::istream& is)
  {
    char rep;
    is >> rep;
    content[row*columns + col] = Cell(rep,should_mutate);
    return content[row*columns + col].isAlive();
  }

  /**
   * retrieves the cell at given location
   * @row is the row location of the cell
   * @col is the column location of the cell
   * @returns the cell at [row, column]
   */
  Cell& getCell(int row, int col)
  {
    return content[row*columns + col];
  }
};
#endif
