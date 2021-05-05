#pragma once
#include <iostream>
#include <string>
#include <map>
# include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
      class Board{
            public:
	      static std::map<City,Color> color;
            static std::map<City,int > disease_level;
            static std::map<City, std::set<City>> connected_cities;
            static std::map<City,bool> research_station;
            static std::map<Color,bool> is_cure;

            Board();
            int &operator[](City);
            friend std::ostream& operator<<(std::ostream &os, const Board &board);
            bool is_clean();
            void remove_cures();
      };
}