#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{

    GeneSplicer::GeneSplicer(Board& b, City c) : Player(b, c) {}
    
    GeneSplicer &GeneSplicer::discover_cure(Color c) { 
        // if(!board.research_station.at(location)){
        //     throw invalid_argument{"cannot discover cure if there is no research station in the location"};
        // }
        // if(board.is_cure.at(c)==true){
        //     return *this;
        // }
        // if(cards.size() < 5){
        //     throw invalid_argument{"you dont have 5 cards to throw"};
        // }
        // else{
        //     int mone = 1;
        //     for(auto iterator = cards.begin(); iterator != cards.end(); mone++){
        //         if(mone == 5){
        //             break; 
        //         }   
        //         iterator = cards.erase(iterator);
        //     }
        //     board.is_cure.at(c)=true;
             return *this;
        // }
    }

    string GeneSplicer::role(){
        return "GeneSplicer";
    }
}

