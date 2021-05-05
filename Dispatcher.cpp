#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{

    Dispatcher::Dispatcher(Board& b, City c) : Player(b, c) {}

    Dispatcher &Dispatcher::fly_direct(City c) { 
        // if(board.research_station.at(location)==true) {
        //     location = c;
        //     return *this;
        // }
        // else {
        //     if(!cards.contains(c)){
        //         throw invalid_argument{"you do not have the card of the city you want to fly"};
        //     }
        //     cards.erase(c);
        //     location = c;
            return *this; 
        //}
    }

    string Dispatcher::role(){
        return "Dispatcher";
    }
}