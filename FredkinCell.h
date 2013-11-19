#ifndef Fredkin_h
#define Fredkin_h

#include "AbstractCell.h"
#include <iostream>


using namespace std;
class FredkinCell : public AbstractCell {
  private:
    unsigned age;
    bool live;
    bool should_live;
  public:
    /** Is this cell currently alive ? */
    bool isAlive() const {return live;}
    void die() {live = false;}
    void reanimate() {live = true;}
    unsigned getAge() const {
      return age;
    }
    void update()
    {
      if(should_live && live)
      {
        reanimate();
        ++age;
      }
      else if(should_live)
        reanimate();
      else
        die();
    }
    void evalLiveness(Grid&);

    void print(std::ostream& os) const {
      if(live)
      {
        if(age <= 9)
          os<< age;
        else
          os<< '+';
      }
      else
        os << '-';
    }

    FredkinCell *clone() const {
      return new FredkinCell(*this);}
    FredkinCell () : age(0), live(false), should_live(false) {}
    FredkinCell (char state) : age(0), live(false), should_live(false)
    {
      if(state == '-')
        live = false;
      if(isdigit(state))
      {
        live = true;
        age = state - '0';
      }
      else if(state == '+')
      {
        live = true;
        age = 10;
      }
    }
    
};

#endif 
