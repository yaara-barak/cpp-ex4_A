#include "Scientist.hpp"

using namespace std;

namespace pandemic
{
    
    Scientist::Scientist(Board& b, City c, int n) : Player(b, c), n(n) {}

    Scientist &Scientist::discover_cure(Color c) { 

        // if(!board.research_station.at(location)){
        //     throw invalid_argument{"cannot discover cure if there is no research station in the location"};
        // }
        // if(board.is_cure.at(c)==true){
        //     return *this;
        // }
        // int mone = 0;
        // for(auto& card : cards){
        //     if(board.color.at(card) == c){
        //         mone++;
        //     }
        // }
        // if(mone < n){
        //     throw invalid_argument{"Scientist dont have enough cards with the correct color"};
        // }
        // else{
        //     mone=1;
        //     for(auto iterator = cards.begin(); iterator != cards.end(); mone++){
        //          if(mone == n) { 
        //              break; 
        //         }
        //         if(board.color.at(*iterator) == c) {
        //             iterator = cards.erase(iterator);
        //         }
        //         else {
        //             ++iterator;
        //         }
        //     }
        //     board.is_cure.at(c)=true;
             return *this;
        // }
	}

    string Scientist::role(){
        return "Scientist";
    }

}