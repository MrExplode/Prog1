#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

using namespace Graph_lib;

bool running = true;

void exit(Address, Address pw)
{
    running = false;
    reference_to<Simple_window>(pw).hide();
}

int main()
{
    try
    {
        Point windowLocation{200, 400};
        Simple_window win{windowLocation, 1000, 800, "drill13"};
        win.wait_for_button();

        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for (int i = 0; i <= x_size; i += 100)
        {
            // horizontal line
            grid.add(Point{0, i}, Point{x_size, i});
            // vertical line
            grid.add(Point{i, 0}, Point{i, y_size});
        }
        win.attach(grid);
        win.wait_for_button();

        Vector_ref<Graph_lib::Rectangle> rectangles;
        for (int i = 0; i < 8; i++)
        {
            rectangles.push_back(new Graph_lib::Rectangle{Point{i * 100, i * 100}, 100, 100});
            rectangles[rectangles.size() - 1].set_fill_color(Color::red);
            win.attach(rectangles[rectangles.size() - 1]);
        }
        win.wait_for_button();

        Image img1{Point(300, 100), "image.jpg"};
        Image img2{Point(100, 300), "image.jpg"};
        Image img3{Point(500, 300), "image.jpg"};
        win.attach(img1);
        win.attach(img2);
        win.attach(img3);
        win.wait_for_button();

        Button exitButton{Point(x_max() - 150, 0), 70, 20, "Exit", exit};
        win.attach(exitButton);

        while (running)
        {
            int x = (rand() % 7 + 1) * 100;
            int y = (rand() % 7 + 1) * 100;
            Image img{Point(x, y), "image.jpg"};
            img.set_mask(Point(50, 50), 100, 100);
            win.attach(img);
            win.wait_for_button();
        }
    }
    catch (exception &e)
    {
        cout << "error:" << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
        return 2;
    }
}