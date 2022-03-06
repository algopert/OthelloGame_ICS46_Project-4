// OthelloBoard.hpp
//
// ICS 46 Winter 2022
// Project #3: Black and White
//
// An OthelloBoard is an object that tracks the current state of an
// Othello board.  A board is a collection of cells, each identified
// by an (x, y) position, where 0 <= x <= width-1 and 0 <= y <= height-1.

#ifndef OTHELLOBOARD_HPP
#define OTHELLOBOARD_HPP

#include "OthelloCell.hpp"



class OthelloBoard
{
public:
    virtual ~OthelloBoard() = default;

    // width() returns the width of this Othello board.
    virtual int width() const noexcept = 0;

    // height() returns the height of this Othello board.
    virtual int height() const noexcept = 0;

    // isValidCell() returns true if the given (x, y) is a valid
    // cell on this board -- i.e., if (x, y) is in the boundaries
    // of the board -- or false otherwise.
    virtual bool isValidCell(int x, int y) const noexcept = 0;

    // cellAt() returns the contents of the cell (x, y).  The cell
    // will either be empty, black, or white.
    virtual OthelloCell cellAt(int x, int y) const = 0;

    // setCellAt() changes the contents of the cell (x, y) to the
    // given new value (empty, black, or white).
    virtual void setCellAt(int x, int y, OthelloCell cell) = 0;

    // placeTile() places a tile on the board in cell (x, y),
    // provided that cell (x, y) is currently empty.  If the
    // cell is not currently empty, an OthelloException is
    // thrown.
    virtual void placeTile(int x, int y, OthelloCell cell) = 0;

    // flipTile() flips the tile on the board in cell (x, y),
    // if any -- so, if it was white, it is now black; if it
    // was black, it is now white.  If the cell is not currently
    // occupied by a tile, an OthelloException is thrown.
    virtual void flipTile(int x, int y) = 0;
};



#endif

