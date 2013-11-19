#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#define private public

#include "Cell.h"
#include "Life.h"
#include "ConwayCell.h"


// ----------
// Tie-Bug
// ----------
// Unit tests to reproduce the tie bug for #15 & #16

TEST(ConwayCell, evalLiveness_lonely_death_0) {
  Life<ConwayCell> l(3,3);
  ConwayCell cc(true);
  std::istringstream iss("3\n3\n...\n.*.\n...\n");
  l.read(iss);
  cc.evalLiveness(l.grid);
  cc.update();
  ASSERT_FALSE(cc.isAlive());
}

TEST(ConwayCell, evalLiveness_lonely_death_1) {
  Life<ConwayCell> l(3,3);
  ConwayCell cc(true);
  std::istringstream iss("3\n3\n...\n.*.\n*..\n");
  l.read(iss);
  cc.evalLiveness(l.grid);
  cc.update();
  ASSERT_FALSE(cc.isAlive());
}

TEST(ConwayCell, evalLiveness_stayin_alive_2) {
  Life<ConwayCell> l(3,3);
  ConwayCell cc(true);
  std::istringstream iss("3\n3\n..*\n.*.\n*..\n");
  l.read(iss);
  cc.evalLiveness(l.grid);
  cc.update();
  ASSERT_TRUE(cc.isAlive());
}

TEST(ConwayCell, evalLiveness_stayin_alive_3) {
  Life<ConwayCell> l(3,3);
  ConwayCell cc(true);
  std::istringstream iss("3\n3\n*.*\n.*.\n*..\n");
  l.read(iss);
  cc.evalLiveness(l.grid);
  cc.update();
  ASSERT_TRUE(cc.isAlive());
}

TEST(ConwayCell, evalLiveness_rebirth) {
  Life<ConwayCell> l(3,3);
  ConwayCell cc;
  std::istringstream iss("3\n3\n*.*\n...\n*..\n");
  l.read(iss);
  cc.evalLiveness(l.grid);
  cc.update();
  ASSERT_TRUE(cc.isAlive());
}

TEST(ConwayCell, evalLiveness_overpop) {
  Life<ConwayCell> l(3,3);
  ConwayCell cc(true);
  std::istringstream iss("3\n3\n*.*\n.*.\n*.*\n");
  l.read(iss);
  cc.evalLiveness(l.grid);
  cc.update();
  ASSERT_FALSE(cc.isAlive());
}

TEST(ConwayCell, evalLiveness_empty) {
  Life<ConwayCell> l(3,3);
  ConwayCell cc;
  std::istringstream iss("3\n3\n...\n...\n...\n");
  l.read(iss);
  cc.evalLiveness(l.grid);
  cc.update();
  ASSERT_FALSE(cc.isAlive());
}

TEST(Fredkin, evalLiveness_lonely_death_0) {
  Life<FredkinCell> l(3,3);
  FredkinCell fc(0);
  std::istringstream iss("3\n3\n---\n-0-\n---\n");
  l.read(iss);
  fc.evalLiveness(l.grid);
  fc.update();
  ASSERT_FALSE(fc.isAlive());
}

TEST(FredkinCell, evalLiveness_lonely_death_2) {
  Life<FredkinCell> l(3,3);
  FredkinCell fc('0');
  std::istringstream iss("3\n3\n-+-\n-0-\n-+-\n");
  l.read(iss);
  fc.evalLiveness(l.grid);
  fc.update();
  ASSERT_FALSE(fc.isAlive());
}

TEST(FredkinCell, evalLiveness_lonely_death_4) {
  Life<FredkinCell> l(3,3);
  FredkinCell fc('0');
  std::istringstream iss("3\n3\n-+-\n+0+\n-+-\n");
  l.read(iss);
  fc.evalLiveness(l.grid);
  fc.update();
  ASSERT_FALSE(fc.isAlive());
}

TEST(FredkinCell, evalLiveness_stayin_alive_1) {
  Life<FredkinCell> l(3,3);
  FredkinCell fc('0');
  std::istringstream iss("3\n3\n-+-\n-0-\n---\n");
  l.read(iss);
  fc.evalLiveness(l.grid);
  fc.update();
  ASSERT_TRUE(fc.isAlive());
}
TEST(FredkinCell, evalLiveness_stayin_alive_3) {
  Life<FredkinCell> l(3,3);
  FredkinCell fc('0');
  std::istringstream iss("3\n3\n-+-\n+0+\n---\n");
  l.read(iss);
  fc.evalLiveness(l.grid);
  fc.update();
  ASSERT_TRUE(fc.isAlive());
}

TEST(FredkinCell, evalLiveness_empty) {
  Life<FredkinCell> l(3,3);
  FredkinCell fc;
  std::istringstream iss("3\n3\n---\n---\n---\n");
  l.read(iss);
  fc.evalLiveness(l.grid);
  fc.update();
  ASSERT_FALSE(fc.isAlive());
}

TEST(FredkinCell, aging) {
  FredkinCell fc('0');
  fc.should_live = true;
  fc.update();
  ASSERT_TRUE(fc.isAlive());
  ASSERT_EQ(fc.age,1);
}

TEST(FredkinCell, aging_plus) {
  FredkinCell fc('9');
  fc.should_live = true;
  fc.update();
  std::ostringstream oss;
  fc.print(oss);
  ASSERT_EQ('+', oss.str()[0]);
}

TEST(Grid, populateGrid_hetero) {
  const char *grid_str =
"\
5\n\
10\n\
..........\n\
..*--.....\n\
..0**.....\n\
..........\n\
..........\n";
  Life<Cell> l(1,1);
  std::istringstream iss(grid_str);
  l.read(iss);
  Grid g(3,3);
  l.grid.populateGrid(0,0,g);
  ASSERT_TRUE(g.getCell(2,2).isAlive());
  ASSERT_TRUE(g.getCell(1,2).isAlive());
  ASSERT_FALSE(g.getCell(1,1).isAlive());
  ASSERT_FALSE(g.getCell(1,0).isAlive());
  ASSERT_FALSE(g.getCell(0,0).isAlive());
  ASSERT_FALSE(g.getCell(0,1).isAlive());
  ASSERT_FALSE(g.getCell(0,2).isAlive());
}
TEST(Cell, mutate) {
  Cell c;
}
