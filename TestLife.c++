#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "ConwayCell.h"


// ----------
// Tie-Bug
// ----------
// Unit tests to reproduce the tie bug for #15 & #16

TEST(Grid, neighbourhood) {
  Grid g(3,3);
  ConwayCell cc;
  cc.evalLiveness(g);
}


