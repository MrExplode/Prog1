#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"

int main()
{
    try
    {

        Point t1{100, 100};

        Simple_window win{t1, 640, 400, "My window"};

        win.wait_for_button();

        Axis xa{Axis::x, Point{30, 300}, 200, 10, "X axis"};

        win.attach(xa);
        win.set_label("X Axis");
        win.wait_for_button();

        Axis ya{Axis::y, Point{30, 300}, 200, 10, "Y axis"};
        ya.set_color(Color::cyan);
        win.attach(ya);
        win.set_label("Y axis");
        win.wait_for_button();

        Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
        win.attach(sine);
        win.set_label("Sine function");
        win.wait_for_button();
        sine.set_color(Color::magenta);

        Graph_lib::Polygon poly;
        poly.add(Point{300, 200});
        poly.add(Point{350, 100});
        poly.add(Point{400, 200});

        poly.set_color(Color::green);
        poly.set_style(Line_style::dashdot);
        win.attach(poly);
        win.set_label("Draw polygon");
        win.wait_for_button();

        Graph_lib::Rectangle r{Point{200, 200}, 150, 70};
        win.attach(r);
        win.set_label("Draw rectangle");
        win.wait_for_button();

        Closed_polyline poly_rect;
        poly_rect.add(Point{100, 50});
        poly_rect.add(Point{200, 50});
        poly_rect.add(Point{200, 100});
        poly_rect.add(Point{100, 100});
        poly_rect.add(Point{50, 75});

        win.attach(poly_rect);
        win.set_label("Draw closed polyline");
        win.wait_for_button();

        r.set_fill_color(Color::yellow);
        poly.set_style(Line_style(Line_style::dash, 5));
        poly_rect.set_style(Line_style(Line_style::dash, 3));
        poly_rect.set_fill_color(Color::green);
        win.set_label("Change colors");
        win.wait_for_button();

        Text t{Point{120, 100}, "Hello, Graphical world!"};
        win.attach(t);
        win.set_label("Text");
        win.wait_for_button();

        t.set_font(Graph_lib::Font::times_bold);
        t.set_font_size(20);
        win.set_label("Change font");
        win.wait_for_button();

        Image ii(Point{100, 50}, "plane.jpg");
        win.attach(ii);
        win.set_label("Draw image");
        win.wait_for_button();

        ii.move(100, 200);
        win.set_label("Move image");
        win.wait_for_button();

        Circle circle{Point{100, 200}, 50};
        Graph_lib::Ellipse ellipse{Point{100, 200}, 75, 25};
        ellipse.set_color(Color::dark_red);
        Mark mark{Point{100, 200}, 'x'};

        ostringstream oss;
        oss << "Screen size: " << x_max() << "*" << y_max()
            << "; windows size: " << win.x_max() << "*" << win.y_max();
        Text size{Point{300, 25}, oss.str()};

        Image cal{Point{225, 225}, "snow.gif"};
        cal.set_mask(Point{40, 100}, 300, 100);

        win.attach(circle);
        win.attach(mark);
        win.attach(ellipse);

        win.attach(size);
        win.attach(cal);
        win.set_label("Extras");
        win.wait_for_button();
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "error\n";
        return 2;
    }
}