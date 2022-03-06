// Alex_OthelloAI.cpp

#include <ics46/factory/DynamicFactory.hpp>
#include "Alex_OthelloAI.hpp"
#include "OthelloCell.hpp"
#include "OthelloGameState.hpp"
#include <vector>
#include <iostream>

using namespace std;

ICS46_DYNAMIC_FACTORY_REGISTER(OthelloAI, anathana::Alex_OthelloAI, "Alex's Engine");

#define N_ROW_COL 8
// Find all valid moves for player
vector<pair<int, int>> anathana::Alex_OthelloAI::findMoves(const OthelloGameState &s)
{
    vector<pair<int, int>> moves;
    for (int row = 0; row < N_ROW_COL; row++)
    {
        for (int col = 0; col < N_ROW_COL; col++)
        {
            if (s.isValidMove(col, row))
            {
                pair<int, int> validMove = make_pair(col, row);
                moves.push_back(validMove);
            }
        }
    }
    return moves;
}



// evaluate each valid move based on advantage and gain
int anathana::Alex_OthelloAI::eval(OthelloGameState &state, OthelloCell &turn)
{
    int result = 0;
    int __evals[8][8] = {
        {100, -20, 10,  5,  5, 10, -20, 100},
        {-20, -50, -2, -2, -2, -2, -50, -20},
        { 10,  -2, -1, -1, -1, -1,  -2,  10},
        {  5,  -2, -1, -1, -1, -1,  -2,   5},
        {  5,  -2, -1, -1, -1, -1,  -2,   5},
        { 10,  -2, -1, -1, -1, -1,  -2,  10},
        {-20, -50, -2, -2, -2, -2, -50, -20},
        {100, -20, 10,  5,  5, 10, -20, 100}};

    const OthelloBoard &board = state.board();
    
    OthelloCell opp_color;
    if (turn == OthelloCell::black)
        opp_color = OthelloCell::white;
    else
        opp_color = OthelloCell::black;

    for (int row = 0; row < board.height(); row++)
    {
        for (int col = 0; col < board.width(); col++)
        {
            if (board.cellAt(col, row)==turn)
                result +=__evals[col][row];
            else if (board.cellAt(col, row)==opp_color)
                result -=__evals[col][row];
        }
    }
    //cout<<result<<endl;
    return result;
}


// look x number of moves into the future to determine best move at moment
int anathana::Alex_OthelloAI::search(OthelloGameState &s, int depth, OthelloCell &myColor, pair<int, int> &bestMove)
{
    OthelloCell current;
    
    if (s.isBlackTurn())
        current = OthelloCell::black;
    else if (s.isWhiteTurn())
        current = OthelloCell::white;

    if (s.isGameOver())
    {
        return eval(s, myColor);
    }

    vector<pair<int, int>> moves = findMoves(s);

    pair<int, int> tempMove = make_pair(0, 0);
    if (depth == 0 or moves.size() == 0)
    {
        return eval(s, myColor);
    }
    else if (current == myColor)
    {
        int max;
        for (int i = 0; i < moves.size(); i++)
        {
            unique_ptr<OthelloGameState> state = s.clone();
            state->makeMove(moves[i].first, moves[i].second);
            int evaluation = search(*state, depth - 1, myColor, tempMove);
            if (i == 0)
            {
                max = evaluation;
                bestMove = moves[i];
            }
            else if (evaluation > max)
            {
                max = evaluation;
                bestMove = moves[i];
            }
        }
        
        return max;
    }
    else
    {
        int min;
        for (int p = 0; p < moves.size(); p++)
        {
            
            unique_ptr<OthelloGameState> state = s.clone();
            state->makeMove(moves[p].first, moves[p].second);
            
            int evaluation = search(*state, depth - 1, myColor, tempMove);
            if (p == 0)
                min = evaluation;
            else if (evaluation < min)
                min = evaluation;
        }
        
        return min;
    }
}

// choose the move based on the best evaluation
pair<int, int> anathana::Alex_OthelloAI::chooseMove(const OthelloGameState &state)
{
    
    pair<int, int> bestMove = make_pair(0, 0);
    vector<pair<int, int>> moves = findMoves(state);
    OthelloCell myColor;

    if (state.isBlackTurn())
        myColor = OthelloCell::black;
    else
        myColor = OthelloCell::white;
    

    unique_ptr<OthelloGameState> s = state.clone();
    search(*s, 4, myColor, bestMove);
    
    return bestMove;
}