#include "Researcher.hpp"

using namespace std;

namespace pandemic
{

    Researcher::Researcher(Board& b, City c) : Player(b, c) {}

    Researcher &Researcher::discover_cure(Color c) {
        // if(board.is_cure.at(c)==true){
        //     return *this;
        // }
        // int mone = 0;
        // for(auto& card : cards){
        //     if(board.color.at(card) == c){
        //         mone++;
        //     }
        // }
        // if(mone < 5){
        //     throw invalid_argument{"you dont have 5 cards with the correct color"};
        // }
        // else{
        //     mone=1;
        //     for(auto iterator = cards.begin(); iterator != cards.end(); mone++){
        //         if(mone == 5) {
        //             break; 
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

    string Researcher::role(){
        return "Researcher";
    }

}