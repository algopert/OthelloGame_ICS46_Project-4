// OthelloGameState.hpp
//
// ICS 46 Winter 2022
// Project #3: Black and White
//
// An OthelloGameState describes the current state of an Othello game:
// what the board looks like, what the score is, whether the game is
// over, whose turn it is, etc.
//
// Every cell on the game board is identified by a pair (x, y), where
// x selects a column and y selects a row.  Both x and y are zero-based,
// so (0, 0) is the top-left cell on the board, (width-1, height-1) is
// the bottom-right cell.

#ifndef OTHELLOGAMESTATE_HPP
#define OTHELLOGAMESTATE_HPP

#include <memory>
#include "OthelloBoard.hpp"



class OthelloGameState
{
public:
    virtual ~OthelloGameState() = default;

    // board() returns a reference to a constant OthelloBoard describing
    // what's on the board in this game state.
    virtual const OthelloBoard& board() const noexcept = 0;

    // blackScore() returns the black player's current score.
    virtual int blackScore() const noexcept = 0;

    // whiteScore() returns the white player's current score.
    virtual int whiteScore() const noexcept = 0;

    // isGameOver() returns true if the game is over in this game state,
    // false otherwise.
    virtual bool isGameOver() const noexcept = 0;

    // isBlackTurn() returns true if it is currently the black player's
    // turn in this game state, false otherwise.
    virtual bool isBlackTurn() const noexcept = 0;

    // isWhiteTurn() returns true if it is currently the white player's
    // turn in this game state, false otherwise.
    virtual bool isWhiteTurn() const noexcept = 0;

    // isValidMove() returns true if the current player whose turn it is
    // can make a valid move at cell (x, y).
    virtual bool isValidMove(int x, int y) const = 0;

    // makeMove() modifies this game state by making a move on behalf of
    // the current player at cell (x, y).  If the move is invalid, an
    // OthelloException is thrown.
    virtual void makeMove(int x, int y) = 0;

    // clone() makes a copy of this game state and returns a unique_ptr
    // to it.
    virtual std::unique_ptr<OthelloGameState> clone() const = 0;
};



#endif

