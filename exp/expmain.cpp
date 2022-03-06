#include <memory>
#include <ics46/factory/DynamicFactory.hpp>
#include "OthelloAI.hpp"
#include "OthelloGameState.hpp"
#include "OthelloGameStateFactory.hpp"
#include "Alex_OthelloAI.hpp"


int main()
{
    // This is how to create objects of the provided AI classes.  All are
    // registered with the ICS 46 DynamicFactory, so this is how you ask
    // for one of them to be built.
    std::unique_ptr<OthelloAI> randomAI =
        ics46::factory::DynamicFactory<OthelloAI>::instance()
        .make("Random Move (Provided)");

    // You can create an object of your own AI without all the ceremony,
    // since you have a full class declaration for it, though you will
    // need to remember to specify the namespace.
    anathana::Alex_OthelloAI myAI;

    // This creates an 8x8 game state with the usual pattern of tiles in
    // the center area.
    std::unique_ptr<OthelloGameState> state =
        OthelloGameStateFactory{}.makeNewGameState(8, 8);

    while (!state->isGameOver())
    {
        // The "auto [x, y]" technique here is something called a "structured
        // binding".  Since chooseMove() returns a std::pair (i.e., something
        // that has two values in it), we can use this technique to assign
        // those two values into separate variables, where those variables'
        // types will automatically be determined to be int, since both of
        // the types in the std::pair are int.
        auto [x, y] = state->isBlackTurn()
            ? randomAI->chooseMove(*state)
            : myAI.chooseMove(*state);

        state->makeMove(x, y);
    }

    return 0;
}