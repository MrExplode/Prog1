#include "Lines_window.h"

Vonalak_ablak::Vonalak_ablak(Pont xy, szám w, szám h, állandó szöveg &title)
    : Ablak{xy, w, h, title},
        next_button{Pont{x_max() - 150, 0}, 70, 20, "Next point", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).next(); }},
        quit_button{Pont{x_max() - 70, 0}, 70, 20, "Quit", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).quit(); }},
        next_x{Pont{x_max() - 310, 0}, 50, 20, "next x:"},
        next_y{Pont{x_max() - 210, 0}, 50, 20, "next y:"},
        xy_out{Pont{100, 0}, 100, 20, "current (x,y):"},
        // coloring
        color_menu{Pont{x_max() - 70, 25}, 70, 20, Menü::függőleges, "color"},
        menu_button{Pont{x_max() - 80, 25}, 80, 20, "color menu", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).color_pressed(); }},
        // styling
        style_menu{Pont{x_max() - 70, 55}, 70, 20, Menü::függőleges, "style"},
        style_button{Pont{x_max() - 80, 55}, 80, 20, "style menu", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).style_pressed(); }},
        style_open{hamis}

{
    csatlakoztat(next_button);
    csatlakoztat(quit_button);
    csatlakoztat(next_x);
    csatlakoztat(next_y);
    csatlakoztat(xy_out);
    csatlakoztat(lines);
  
    // coloring
    color_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "red", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).red_pressed(); }});
    color_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "blue", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).blue_pressed(); }});
    color_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "black", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).black_pressed(); }});
    csatlakoztat(color_menu);
    color_menu.elrejt();
    csatlakoztat(menu_button);
  
    // styling
    style_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "solid", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).solid_pressed(); }});
    style_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "dash", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).dash_pressed(); }});
    style_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "dot", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).dot_pressed(); }});
    style_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "- .", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).dashdot_pressed(); }});
    style_menu.csatlakoztat(új Gomb{Pont{0, 0}, 0, 0, "- . .", [](Cím, Cím pw) { referencia_hozzá<Vonalak_ablak>(pw).dashdotdot_pressed(); }});
    csatlakoztat(style_menu);
    style_menu.elrejt();
    csatlakoztat(style_button);
}

void Vonalak_ablak::quit() { elrejt(); }

void Vonalak_ablak::next() {
    int x = next_x.szerez_szám();
    int y = next_y.szerez_szám();
  
    lines.hozzáad(Pont{x, y});
  
    kiszövegfolyam ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.rak(ss.szöv());
  
    újrarajzol();
}