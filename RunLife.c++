// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ -o RunLife
    % valgrind RunLife > RunLife.out

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <fstream> //ifstream
#include <stdexcept> // invalid_argument, out_of_range
#include "Life.h"
#include "ConwayCell.h"

// ----
// main
// ----

int main (int argc, char **argv) {
    using namespace std;
    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
        /*
        read RunLifeConway.in // assume all Conway cells
        Simulate 283 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.
        */

        Life<ConwayCell> life(1,1);
        ifstream myf;
        myf.open("RunLifeConway.in");

        life.read(myf);
        for (int i = 0 ; i <= 2500; i++)
        {
            if (i < 10 || i == 283 || i == 323 || i == 2500)
                life.print();
            life.step();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        Life<FredkinCell> life(1,1);
        ifstream myf;
        myf.open("RunLifeFredkin.in");
        life.read(myf);

        for (int i = 0 ; i <= 5; i++)
        {
          life.print();
          life.step();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        Life<FredkinCell> life(1,1);
        ifstream myf;
        myf.open("RunLifeCell.in");
        life.read(myf);
        for (int i = 0 ; i <= 5; i++)
        {
          life.print();
          life.step();
        }
    }
    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    return 0;}
