#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"
#include "hulang.h"

szám fő()
{
    próbál
    {
        Pont t1{100, 100};

        Egyszerű_ablak win{t1, 640, 400, "Saját ablak"};

        win.várj_a_gombra();

        Tengely xa{Tengely::x, Pont{30, 300}, 200, 10, "X tengely"};

        win.csatlakoztat(xa);
        win.címke_beállít("X Tengely");
        win.várj_a_gombra();

        Tengely ya{Tengely::y, Pont{30, 300}, 200, 10, "Y tengely"};
        ya.szín_beállít(Szín::türkiz);
        win.csatlakoztat(ya);
        win.címke_beállít("Y Tengely");
        win.várj_a_gombra();

        Funkció sine{sin, 0, 100, Pont{20, 150}, 1000, 50, 50};
        win.csatlakoztat(sine);
        win.címke_beállít("Szinusz funkció");
        win.várj_a_gombra();
        sine.szín_beállít(Szín::magenta);

        Grafikus_könyvtár::Sokszög poly;
        poly.hozzáad(Pont{300, 200});
        poly.hozzáad(Pont{350, 100});
        poly.hozzáad(Pont{400, 200});

        poly.szín_beállít(Szín::zöld);
        poly.stílus_beállít(Vonal_stílus::csíkpont);
        win.csatlakoztat(poly);
        win.címke_beállít("Sokszög rajzolás");
        win.várj_a_gombra();

        Grafikus_könyvtár::Téglalap r{Pont{200, 200}, 150, 70};
        win.csatlakoztat(r);
        win.címke_beállít("Téglalap rajzolás");
        win.várj_a_gombra();

        Closed_polyline poly_rect;
        poly_rect.hozzáad(Pont{100, 50});
        poly_rect.hozzáad(Pont{200, 50});
        poly_rect.hozzáad(Pont{200, 100});
        poly_rect.hozzáad(Pont{100, 100});
        poly_rect.hozzáad(Pont{50, 75});

        win.csatlakoztat(poly_rect);
        win.címke_beállít("Draw closed polyline");
        win.várj_a_gombra();

        r.kitöltő_szín_beállít(Szín::sárga);
        poly.stílus_beállít(Vonal_stílus(Vonal_stílus::csík, 5));
        poly_rect.stílus_beállít(Vonal_stílus(Vonal_stílus::csík, 3));
        poly_rect.kitöltő_szín_beállít(Szín::zöld);
        win.címke_beállít("Change colors");
        win.várj_a_gombra();

        Szöveg t{Pont{120, 100}, "Szia, Grafikus világ!"};
        win.csatlakoztat(t);
        win.címke_beállít("Szöveg");
        win.várj_a_gombra();

        t.betűtípus_beáll(Grafikus_könyvtár::Betűtípus::times_bold);
        t.betűméret_beáll(20);
        win.címke_beállít("Betűtípus megváltoztatása");
        win.várj_a_gombra();

        Kép ii(Pont{100, 50}, "plane.jpg");
        win.csatlakoztat(ii);
        win.címke_beállít("Kép rajzolás");
        win.várj_a_gombra();

        ii.mozgat(100, 200);
        win.címke_beállít("Kép mozgatás");
        win.várj_a_gombra();

        Kör circle{Pont{100, 200}, 50};
        Grafikus_könyvtár::Elipszis ellipse{Pont{100, 200}, 75, 25};
        ellipse.szín_beállít(Szín::sötét_piros);
        Jel mark{Pont{100, 200}, 'x'};

        kiszövegfolyam oss;
        oss << "Screen size: " << x_max() << "*" << y_max()
            << "; windows size: " << win.x_max() << "*" << win.y_max();
        Szöveg size{Pont{300, 25}, oss.szöv()};

        Kép cal{Pont{225, 225}, "snow.gif"};
        cal.maszk_beállít(Pont{40, 100}, 300, 100);

        win.csatlakoztat(circle);
        win.csatlakoztat(mark);
        win.csatlakoztat(ellipse);

        win.csatlakoztat(size);
        win.csatlakoztat(cal);
        win.címke_beállít("Extras");
        win.várj_a_gombra();
    }
    elkap (kivétel &e)
    {
        chiba << "kivétel: " << e.mi() << '\n';
        visszaad 1;
    }
    elkap (...)
    {
        chiba << "error\n";
        visszaad 2;
    }
}