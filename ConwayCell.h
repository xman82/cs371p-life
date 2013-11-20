#ifndef CONWAY_CELL_H
#define CONWAY_CELL_H

#include "AbstractCell.h"
#include <iostream>
#include <vector>
using namespace std;

class ConwayCell : public AbstractCell {
  bool live;
  bool should_live;
  public:
    /** Is this cell currently alive ? */
    bool isAlive () const;
    ConwayCell ();
    unsigned getAge() const {
      return 0;
    }
    /**
     * Constructs ConwayCell based on char representation
     * @param state the character representation of ConwayCell desired
     */
    ConwayCell (char state)
    {
      if (state == '.')
      {
        live = false;
      }
      else if (state == '*')
      {
        live = true;
      }
    }

    /**
     * Constructs ConwayCell with given state
     * @param state true if the ConwayCell is meant to be alive, false if dead
     */
    ConwayCell (bool state)
    {
      live = state;
    }
    ConwayCell* clone () const {
      return new ConwayCell(*this);}
    void print (std::ostream& os) const {
      if(this->isAlive())
        os<< '*';
      else
        os<<'.';
    }
    void die();
    void reanimate ();
    void update();
    void evalLiveness (Grid& neighbourhood);
};

#endif
