/*
    Lesson 2: git basics
*/

#include "../gui/Simple_window.h"
#include "../gui/Graph.h"

using namespace Graph_lib;

int main() {
    try {
        Point windowLocation {200, 400};
        Simple_window win {windowLocation, 1000, 800, "week2 class"};
        win.wait_for_button();

        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for (int i = 0; i <= x_size; i+= 100) {
            //horizontal line
            grid.add(Point{0, i}, Point{x_size, i});
            //vertical line
            grid.add(Point{i, 0}, Point{i, y_size});
        }
        win.attach(grid);
        win.wait_for_button();

        Vector_ref<Graph_lib::Rectangle> rectangles;
        for (int i = 0; i < 8; i++) {
            rectangles.push_back(new Graph_lib::Rectangle{Point{i * 100, i * 100}, 100, 100});
            rectangles[rectangles.size() - 1].set_fill_color(Color::red);
            win.attach(rectangles[rectangles.size() - 1]);
        }
        win.wait_for_button();
    } catch (exception& e) {
        cout << "error:" << e.what() << endl;
        return 1;
    } catch (...) {
        cout << "unknown error" << endl;
        return 2;
    }
}