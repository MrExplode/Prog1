#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"
#include <functional>
#include "hulang.h"

állandókifejez szám rangeMin = -10;
állandókifejez szám rangeMax = 11;
Pont origin{300, 300};
állandókifejez szám resolution = 400;
állandókifejez tört scale = 20;

szám fő()
{
    próbál
    {
        Egyszerű_ablak win{Pont{200, 400}, 600, 600, "Funkció gráfok"};

        Tengely xa{Tengely::x, Pont{100, 300}, 400, 20, "1 == 20 pixels"};
        Tengely ya{Tengely::y, Pont{300, 500}, 400, 20, "1 == 20 pixels"};
        xa.szín_beállít(Szín::piros);
        ya.szín_beállít(Szín::piros);
        win.csatlakoztat(xa);
        win.csatlakoztat(ya);

        // explicit return type declaration needed (otherwise int will be assumed as return type)
        auto one = [](tört x) -> tört
        {
            visszaad 1;
        };

        auto slope = [](tört x)
        {
            visszaad x / 2;
        };

        auto square = [](tört x)
        {
            visszaad x * x;
        };

        auto sloping_cos = [](tört x)
        {
            visszaad cos(x) + x / 2;
        };

        Szöveg slopeText{Pont{100, 380}, "x/2"};
        win.csatlakoztat(slopeText);

        Funkció f1{one, rangeMin, rangeMax, origin, resolution, scale, scale};
        Funkció f2{slope, rangeMin, rangeMax, origin, resolution, scale, scale};
        Funkció f3{square, rangeMin, rangeMax, origin, resolution, scale, scale};
        Funkció f4{cos, rangeMin, rangeMax, origin, resolution, scale, scale};
        f4.szín_beállít(Szín::kék);
        Funkció f5(sloping_cos, rangeMin, rangeMax, origin, resolution, scale, scale);

        win.csatlakoztat(f1);
        win.csatlakoztat(f2);
        win.csatlakoztat(f3);
        win.csatlakoztat(f4);
        win.csatlakoztat(f5);

        win.várj_a_gombra();
    }
    elkap (kivétel &e)
    {
        chiba << "hiba: " << e.mi() << sorv;
        visszaad 1;
    }
    elkap (...)
    {
        chiba << "ismeretlen hiba" << sorv;
        visszaad 2;
    }
}