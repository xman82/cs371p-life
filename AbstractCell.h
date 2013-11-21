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
    /** bring back to life */
    virtual void reanimate () = 0;
    /** reanimate or die based on neighbors
     *
     * evalLiveness must run first */
    virtual void update() = 0;
    /** Returns the age of a Fredkin or 0 if a Conway
     * @return the age*/
    virtual unsigned getAge() const = 0;
    /** determine if we are fit to live another day
     * @param neighbourhood the cells around this one */
    virtual void evalLiveness (Grid& neighbourhood) = 0;
    /** print the cell out
     * @param os where to print */
    virtual void print (std::ostream& os) const = 0;
    /** Returns a copy of this Cell
     * @return the copy
     */
    virtual AbstractCell *clone() const = 0;
    virtual ~AbstractCell() {};
};

#endif
