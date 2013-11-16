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
    void die();
    void reanimate ();
    void update();
    void evalLiveness (Grid& neighbourhood);
};

ostream& operator<<(ostream& os, const ConwayCell& cc);
istream& operator>>(istream& is, ConwayCell& cc);

#endif
