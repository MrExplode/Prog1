/*
    Lesson 1: gui basics
*/

#include "../gui/Simple_window.h"
#include "../gui/Graph.h"
#include <string>
#include <iostream>

using namespace Graph_lib;

int main() {
        try {
                Point t1 {100, 100};
                Simple_window win {t1, 640, 480, "week1 class"};
                win.wait_for_button();

                Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
                win.attach(xa);
                win.wait_for_button();

                Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
                ya.set_color(Color::cyan);
                win.attach(ya);
                win.wait_for_button();

                Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
                win.attach(sine);
                win.wait_for_button();

                Graph_lib::Polygon poly;
                poly.add(Point{300, 200});
                poly.add(Point{350, 100});
                poly.add(Point{400, 200});
                poly.set_color(Color::red);
                poly.set_style(Line_style::dash);
                win.attach(poly);
                win.wait_for_button();

                Graph_lib::Rectangle r {Point{200, 200}, 100, 50};
                win.attach(r);

                Closed_polyline poly_rect;
                poly_rect.add(Point{100, 50});
                poly_rect.add(Point{200, 50});
                poly_rect.add(Point{200, 100});
                poly_rect.add(Point{50, 75});
                win.attach(poly_rect);

                win.wait_for_button();
        } catch (exception& e) {
                cerr << "ayo " << e.what() << endl;
        } catch (...) {
                cerr << "xd" << endl;
        }
}
