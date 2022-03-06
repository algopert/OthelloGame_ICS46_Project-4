// Alex_OthelloAI.hpp

#include "OthelloAI.hpp"
using namespace std;

namespace anathana
{
    class Alex_OthelloAI : public OthelloAI
    {
    public:
		virtual pair<int,int> chooseMove(const OthelloGameState& state);
		vector<pair<int,int>> findMoves(const OthelloGameState& s);
		int search(OthelloGameState &s, int depth, OthelloCell &myColor, pair<int, int> &bestMove);
		int eval(OthelloGameState& state,OthelloCell& turn);
		
    
    };
}