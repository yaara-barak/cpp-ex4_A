#include "Medic.hpp"

using namespace std;

namespace pandemic
{

    Medic::Medic(Board& b, City c) : Player(b, c) {}
    
    Medic &Medic::treat(City c) { 
        // if (c != location){
        //     throw invalid_argument{"not your location! cannot treat"};
        // }
        // else{
        //     if (board.disease_level.at(c)==0){
        //         throw invalid_argument{"alredy cured"};
        //     }
        //     else{
        //             board.disease_level.at(c)=0;
        //         }
        //     }
        return *this;
    }

    string Medic::role(){
        return "Medic";
    }
}