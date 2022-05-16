#include "../../gui/GUI.h"
#include "hulang.h"

használ névűr Grafikus_könyvtár;

struktúra Vonalak_ablak : Grafikus_könyvtár::Ablak {
    Lines_window(Pont xy, szám w, szám h, állandó szöveg &title);

privát:
    Open_polyline lines;

    Gomb next_button;
    Gomb quit_button;

    Be_doboz next_x;
    Be_doboz next_y;

    Ki_doboz xy_out;

    // coloring options
    Menü color_menu;
    Gomb menu_button;

    // styling options
    Menü style_menu;
    Gomb style_button;
    // track menu state
    logikai style_open;

    üresség next();
    üresség quit();

    logikai várj_a_gombra();

    üresség change(Szín c) { lines.szín_beállít(c); }
    üresség change_style(Vonal_stílus s) { lines.stílus_beállít(s); }

    üresség hide_color_menu() {
        color_menu.elrejt();
        menu_button.mutat();
        style_button.mozgat(0, -50);
        style_menu.mozgat(0, -50);
        // on move the widget resets to visible
        ha (!style_open)
            style_menu.elrejt();
        különben
            style_button.elrejt();
    }

    üresség hide_style_menu() {
        style_menu.elrejt();
        style_button.mutat();
        style_open = hamis;
    }

    üresség red_pressed() {
        change(Szín::piros);
        hide_color_menu();
    }

    üresség blue_pressed() {
        change(Szín::kék);
        hide_color_menu();
    }

    üresség black_pressed() {
        change(Szín::fekete);
        hide_color_menu();
    }

    üresség color_pressed() {
        menu_button.elrejt();
        color_menu.show();

        style_button.mozgat(0, 50);
        style_menu.mozgat(0, 50);
        ha (!style_open)
            style_menu.elrejt();
        különben
            style_button.elrejt();
    }

    üresség solid_pressed() {
        change_style(Vonal_stílus::tömör);
        hide_style_menu();
    }

    üresség dash_pressed() {
        change_style(Vonal_stílus::csík);
        hide_style_menu();
    }

    üresség dot_pressed() {
        change_style(Vonal_stílus::pont);
        hide_style_menu();
    }

    üresség dashdot_pressed() {
        change_style(Vonal_stílus::csíkpont);
        hide_style_menu();
    }

    üresség dashdotdot_pressed() {
        change_style(Vonal_stílus::csíkpontpont);
        hide_style_menu();
    }

    üresség style_pressed() {
        style_button.hide();
        style_menu.mutat();
        style_open = igaz;
    }
};