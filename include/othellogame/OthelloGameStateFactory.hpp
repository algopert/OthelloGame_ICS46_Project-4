// OthelloGameStateFactory.hpp
//
// ICS 46 Winter 2022
// Project #3: Black and White
//
// A class for creating OthelloGameState objects, while hiding the details of
// how they're implemented.  You may not find yourself need this in your
// implementation, but it is necessary in other parts of the application.

#ifndef OTHELLOGAMESTATEFACTORY_HPP
#define OTHELLOGAMESTATEFACTORY_HPP

#include <memory>
#include <vector>
#include "OthelloGameState.hpp"



class OthelloGameStateFactory
{
public:
    // makeNewGameState() takes a width and a height and creates a new
    // Othello game board with that given width and height.  The width
    // and height must both be at least 4, or else an OthelloException
    // is thrown.
    std::unique_ptr<OthelloGameState> makeNewGameState(int width, int height);


    // makeGameState() takes a complete game state -- described by the
    // given parameters -- and builds an OthelloGameState object
    // with those parameters.  (This is primarily used in the Othello
    // tournament.)
    std::unique_ptr<OthelloGameState> makeGameState(
        int width, int height,
        bool isGameOver, bool isWhiteTurn,
        const std::vector<OthelloCell>& cells);
};



#endif

