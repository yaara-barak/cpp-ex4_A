
#include "Player.hpp"

using namespace std;

namespace pandemic {
    Player::Player(Board &b, City c) : board(b), location(c) {}

    Player& Player::drive(City c){
        // if(!board.connected_cities.at(location).contains(c)){
        //     throw invalid_argument{"cannot drive to not neighbor city"};
        //     //throw invalid_argument{"cannot move from" + location + "to " + c};
        // }
        // location=c;
        return *this;
    }

    Player& Player::fly_direct(City c){
        // if(!cards.contains(c)){
        //     throw invalid_argument{"you do not have the card of the city you want to fly"};
        // }
        // cards.erase(c);
        // location = c;
        return *this;   
    }
     Player& Player::fly_charter(City c){
        // if(!cards.contains(location)){
        //     throw invalid_argument{"you do not have the card of the city you want to fly"};
        // }
        // cards.erase(location);
        // location = c;
        return *this;   
    }
    Player& Player::fly_shuttle(City c){
        // if(!board.research_station.at(location) || !board.research_station.at(c)){
        //     throw invalid_argument{"one of the cities dont have a research station"};
        // }
        // location = c;
        return *this;
    }
    Player& Player::build(){
        // if(!cards.contains(location)){
        //     throw invalid_argument{"cannot build research station if the player dont have a card of the city"};
        // }
        // if(board.research_station.at(location)== true){
        //      return *this;
        // }
        // board.research_station.at(location)= true;
        // cards.erase(location);
        return *this;
    }
    Player& Player::discover_cure(Color c){
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
        //}
	}
    
    Player& Player::treat(City c){
        // if (c != location){
        //     throw invalid_argument{"not your location! cannot treat"};
        // }
        // else{
        //     if (board.disease_level.at(c)==0){
        //         throw invalid_argument{"alredy cured"};
        //     }
        //     else{
        //         if(board.is_cure.at(board.color.at(c))==true){
        //             board.disease_level.at(c)=0;
        //         }
        //         else{
        //             board.disease_level.at(c)--;
        //         }
        //     }
        return *this;
        //}
    }

    Player& Player::take_card(City c){
        // cards.insert(c);
        return *this;
    }
    string Player::role(){
		return "basic player";
	}

}