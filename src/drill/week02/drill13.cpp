#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"
#include "hulang.h"

használ névűr Grafikus_könyvtár;

logikai running = igaz;

üresség kijárat(Cím, Cím pw)
{
    running = hamis;
    referencia_hozzá<Egyszerű_ablak>(pw).elrejt();
}

szám fő()
{
    próbál
    {
        Pont windowLocation{200, 400};
        Egyszerű_ablak win{windowLocation, 1000, 800, "drill13"};
        win.várj_a_gombra();

        Vonalak grid;
        int x_size = 800;
        int y_size = 800;
        mert (szám i = 0; i <= x_size; i += 100)
        {
            // horizontal line
            grid.hozzáad(Pont{0, i}, Pont{x_size, i});
            // vertical line
            grid.add(Pont{i, 0}, Pont{i, y_size});
        }
        win.csatlakoztat(grid);
        win.várj_a_gombra();

        Vector_ref<Grafikus_könyvtár::Téglalap> rectangles;
        mert (szám i = 0; i < 8; i++)
        {
            rectangles.nyom_hátra(új Grafikus_könyvtár::Téglalap{Pont{i * 100, i * 100}, 100, 100});
            rectangles[rectangles.méret() - 1].kitöltő_szín_beállít(Szín::piros);
            win.csatlakoztat(rectangles[rectangles.méret() - 1]);
        }
        win.várj_a_gombra();

        Kép img1{Pont(300, 100), "image.jpg"};
        Kép img2{Pont(100, 300), "image.jpg"};
        Kép img3{Pont(500, 300), "image.jpg"};
        win.csatlakoztat(img1);
        win.csatlakoztat(img2);
        win.csatlakoztat(img3);
        win.várj_a_gombra();

        Gomb exitButton{Pont(x_max() - 150, 0), 70, 20, "Kijárat", kijárat};
        win.csatlakoztat(exitButton);

        miközben (running)
        {
            szám x = (véletlen() % 7 + 1) * 100;
            szám y = (véletlen() % 7 + 1) * 100;
            Kép img{Pont(x, y), "image.jpg"};
            img.maszk_beállít(Pont(50, 50), 100, 100);
            win.csatlakoztat(img);
            win.várj_a_gombra();
        }
    }
    elkap (kivétel &e)
    {
        cki << "hiba:" << e.mi() << sorv;
        visszaad 1;
    }
    elkap (...)
    {
        cki << "ismeretlen hiba" << sorv;
        visszaad 2;
    }
}