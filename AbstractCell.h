#ifndef ABSTRACT_CELL_H
#define ABSTRACT_CELL_H
#include <vector>
#include <iostream>
#include <ctype.h>

using namespace std;

class Grid;
class AbstractCell {
  bool live;
  bool should_live;
  public:
    /** Is this cell currently alive ? */
    AbstractCell() : live(false), should_live(false) {}
    virtual bool isAlive () const = 0;
    virtual void die() = 0;
    virtual void reanimate () = 0;
    virtual void update() = 0;
    virtual unsigned getAge() const = 0;
    virtual void evalLiveness (Grid& neighbourhood) = 0;
    virtual void print (std::ostream& os) const = 0;
    virtual AbstractCell *clone() const = 0;
};

#endif
