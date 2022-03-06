// OthelloAI.hpp
//
// ICS 46 Winter 2022
// Project #3: Black and White
//
// An AI capable of playing Othello is implemented by creating a new class
// that inherits from this one.  Its only public function is one that
// takes an OthelloGameState and chooses a move.

#ifndef OTHELLOAI_HPP
#define OTHELLOAI_HPP

#include <utility>
#include "OthelloGameState.hpp"



class OthelloAI
{
public:
    virtual ~OthelloAI() = default;

    // chooseMove() takes a constant OthelloGameState and decides on
    // a move, returning a std::pair whose elements describe the (x, y)
    // coordinate of the cell where the chosen move should be made.
    virtual std::pair<int, int> chooseMove(const OthelloGameState& state) = 0;
};



#endif

