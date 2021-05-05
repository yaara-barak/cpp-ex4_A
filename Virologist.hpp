#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
    public:
      Virologist(Board&, City);
      Virologist &treat(City);
      std::string role();

    };
}