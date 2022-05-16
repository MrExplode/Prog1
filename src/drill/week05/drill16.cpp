#include "../../gui/GUI.h"
#include "Lines_window.h"
#include "hulang.h"

szám fő()
{
    próbál
    {
        Vonalak_ablak win{Pont{100, 100}, 600, 400, "vonalak"};
        visszaad gui_main();
    }
    elkap (kivétel &e)
    {
        alap::chiba << "kivétel: " << e.mi() << alap::sorv;
        visszaad 1;
    }
    elkap (...)
    {
        alap::chiba << "ismeretlen kivétel történt!" << alap::sorv;
        visszaad 2;
    }
}