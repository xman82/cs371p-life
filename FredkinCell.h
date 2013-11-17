class FredkinCell : public AbstractCell {
  bool live;
  bool should_live;
  unsigned age;
  public:
    /** Is this cell currently alive ? */
    bool isAlive() const {return true;}
    void die(){}
    void reanimate(){}
    void update(){}
    void evalLiveness(){}
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
    FredkinCell ();
    FredkinCell (char state)
    {
      if(state == '-')
        live = false;
      else
        live = true;
    }
};

