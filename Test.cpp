#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "doctest.h"

using namespace pandemic;

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

Board board;

TEST_CASE("basic board checks"){
    CHECK_NOTHROW(board[City::Tokyo] = 4);      // red
    CHECK_NOTHROW(board[City::Chicago] = 1);    // blue
    CHECK_NOTHROW(board[City::LosAngeles] = 2); // Yellow
    CHECK_NOTHROW(board[City::MexicoCity] = 2); // Yellow
    CHECK_NOTHROW(board[City::Paris] = 1);      // Blue
    CHECK_NOTHROW(board[City::Mumbai] = 3);     // Black
    CHECK_NOTHROW(board[City::Essen] = 2);    // Black
    CHECK_NOTHROW(board[City::Seoul] = 4);    // Red

    CHECK_NOTHROW(board.remove_cures());
    //CHECK(board.is_clean() == true);
}

TEST_CASE("basic player checks"){
    Player player{board, City::Seoul};
    CHECK_NOTHROW(player.take_card(City::HongKong));
    CHECK_NOTHROW(player.take_card(City::Shanghai));
    CHECK_NOTHROW(player.take_card(City::Tokyo));
    CHECK_NOTHROW(player.take_card(City::Seoul));
    CHECK_NOTHROW(player.take_card(City::Bangkok));

    CHECK_NOTHROW(player.drive(City::Shanghai));
    CHECK_NOTHROW(player.fly_direct(City::Bangkok));
    CHECK_NOTHROW(player.drive(City::HongKong));
    CHECK_NOTHROW(player.fly_charter(City::Tokyo));
    CHECK_NOTHROW(player.build());
}

TEST_CASE("OperationsExpert"){
//יכול לבצע פעולת "בנייה" בכל עיר שהוא נמצא בה, בלי להשליך קלף-עיר מתאים
    OperationsExpert Op_Ex{board, City::Tokyo};
    CHECK_NOTHROW(Op_Ex.take_card(City::Bogota));
    CHECK_NOTHROW(Op_Ex.take_card(City::Bangkok));
    CHECK_NOTHROW(Op_Ex.take_card(City::Chennai));
    CHECK_NOTHROW(Op_Ex.take_card(City::Delhi));
    CHECK_NOTHROW(Op_Ex.take_card(City::SaoPaulo));

    CHECK_NOTHROW(Op_Ex.build());

    CHECK_EQ(Op_Ex.role(), string("OperationsExpert"));
}

TEST_CASE("Dispatcher"){
//כשהוא נמצא בתחנת-מחקר, הוא יכול לבצע פעולת "טיסה ישירה" לכל עיר שהוא רוצה, ללא השלכת קלף-עיר
    Dispatcher Dis{board, City::Tokyo};
    CHECK_NOTHROW(Dis.take_card(City::Bogota));
    CHECK_NOTHROW(Dis.take_card(City::MexicoCity));
    CHECK_NOTHROW(Dis.take_card(City::Chennai));
    CHECK_NOTHROW(Dis.take_card(City::Delhi));
    CHECK_NOTHROW(Dis.take_card(City::SaoPaulo));

    CHECK_NOTHROW(Dis.fly_direct(City::MexicoCity););
    CHECK_NOTHROW(Dis.build());
    CHECK_NOTHROW(Dis.fly_direct(City::Paris));

    CHECK_EQ(Dis.role(), string("Dispatcher"));
}

TEST_CASE("Scientist"){
// יכולה לבצע פעולת "גילוי תרופה" בעזרת n קלפים בלבד (במקום 5), כאשר הפרמטר n מועבר בבנאי (במשחק המקורי n=4).
    Scientist Sci{board, City::Delhi, 3};
    CHECK_NOTHROW(Sci.take_card(City::Bogota));
    CHECK_NOTHROW(Sci.take_card(City::Bangkok));
    CHECK_NOTHROW(Sci.take_card(City::Chennai));
    CHECK_NOTHROW(Sci.take_card(City::Delhi));
    CHECK_NOTHROW(Sci.take_card(City::SaoPaulo));

    //CHECK_THROWS(Sci.discover_cure(Color::Blue));
    
    CHECK_EQ(Sci.role(), string("Scientist"));
}

TEST_CASE("Researcher"){
//יכולה לבצע פעולת "גילוי תרופה" בכל עיר - לא חייבת להיות בתחנת מחקר.
    Researcher Res{board, City::Paris};
    CHECK_NOTHROW(Res.take_card(City::LosAngeles));
    CHECK_NOTHROW(Res.take_card(City::MexicoCity));
    CHECK_NOTHROW(Res.take_card(City::BuenosAires));
    CHECK_NOTHROW(Res.take_card(City::Johannesburg));
    CHECK_NOTHROW(Res.take_card(City::Kinshasa));

    CHECK_NOTHROW(Res.discover_cure(Color::Yellow););

    CHECK_EQ(Res.role(), string("Researcher"));
}

TEST_CASE("Medic"){
//כשהוא מבצע פעולת "טיפול במחלה", הוא מוריד את כל קוביות-המחלה מהעיר שהוא נמצא בה, ולא רק אחת.
    Medic Med{board, City::Mumbai};
    CHECK_NOTHROW(Med.take_card(City::Bogota));
    CHECK_NOTHROW(Med.take_card(City::Bangkok));
    CHECK_NOTHROW(Med.take_card(City::Chennai));
    CHECK_NOTHROW(Med.take_card(City::Delhi));
    CHECK_NOTHROW(Med.take_card(City::SaoPaulo));

    CHECK_NOTHROW(Med.treat(City::Mumbai));
    CHECK(board[City::Mumbai] == 0);
    
    CHECK_EQ(Med.role(), string("Medic"));
}

TEST_CASE("Virologist"){
//יכולה לבצע פעולת "טיפול במחלה", לא רק בעיר שהיא נמצאת בה, אלא בכל עיר בעולם - ע"י השלכת קלף של אותה העיר.
    Virologist Vir{board, City::Bogota};
    CHECK_NOTHROW(Vir.take_card(City::Tokyo));
    CHECK_NOTHROW(Vir.take_card(City::Bangkok));
    CHECK_NOTHROW(Vir.take_card(City::Chennai));
    CHECK_NOTHROW(Vir.take_card(City::Delhi));
    CHECK_NOTHROW(Vir.take_card(City::SaoPaulo));

    CHECK_NOTHROW(Vir.treat(City::Tokyo));
    CHECK(board[City::Tokyo] == 3);

    CHECK_EQ(Vir.role(), string("Virologist"));
}

TEST_CASE("GeneSplicer"){
// יכולה לבצע פעולת "גילוי תרופה" בעזרת 5 קלפים כלשהם - לא דווקא מהצבע של המחלה.
    GeneSplicer Gen_Sp{board, City::Tokyo};
    CHECK_NOTHROW(Gen_Sp.take_card(City::Tokyo));
    CHECK_NOTHROW(Gen_Sp.take_card(City::Bangkok));
    CHECK_NOTHROW(Gen_Sp.take_card(City::Chennai));
    CHECK_NOTHROW(Gen_Sp.take_card(City::Delhi));
    CHECK_NOTHROW(Gen_Sp.take_card(City::SaoPaulo));

    CHECK_NOTHROW(Gen_Sp.discover_cure(Color::Black));
    CHECK_NOTHROW(Gen_Sp.treat(City::Tokyo));
    CHECK(board[City::Tokyo] == 2);

    CHECK_EQ(Gen_Sp.role(), string("GeneSplicer"));
}

TEST_CASE("FieldDoctor"){
//יכול לבצע פעולת "טיפול במחלה" לא רק בעיר שהוא נמצא בה אלא בכל עיר סמוכה לעיר שהוא נמצא בה (ע"פ מפת הקשרים), בלי להשליך קלף עיר.
    FieldDoctor Fi_Doc{board, City::Paris};
    CHECK_NOTHROW(Fi_Doc.take_card(City::Tokyo));
    CHECK_NOTHROW(Fi_Doc.take_card(City::Bangkok));
    CHECK_NOTHROW(Fi_Doc.take_card(City::Chennai));
    CHECK_NOTHROW(Fi_Doc.take_card(City::Delhi));
    CHECK_NOTHROW(Fi_Doc.take_card(City::SaoPaulo));

    CHECK_NOTHROW(Fi_Doc.treat(City::Essen));
    CHECK(board[City::Essen] == 1);
  
    CHECK_EQ(Fi_Doc.role(), string("FieldDoctor"));
}
