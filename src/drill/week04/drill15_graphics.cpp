#include "../../gui/Simple_window.h"
#include "../../gui/Graph.h"
#include <functional>

constexpr int rangeMin = -10;
constexpr int rangeMax = 11;
Point origin{300, 300};
constexpr int resolution = 400;
constexpr double scale = 20;

int main()
{
    try
    {
        Simple_window win{Point{200, 400}, 600, 600, "Function graphs"};

        Axis xa{Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
        Axis ya{Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
        xa.set_color(Color::red);
        ya.set_color(Color::red);
        win.attach(xa);
        win.attach(ya);

        // explicit return type declaration needed (otherwise int will be assumed as return type)
        auto one = [](double x) -> double
        {
            return 1;
        };

        auto slope = [](double x)
        {
            return x / 2;
        };

        auto square = [](double x)
        {
            return x * x;
        };

        auto sloping_cos = [](double x)
        {
            // this is the place where I'd do a fancy local capture
            // but a lambda can only be converted to a function pointer if it does not capture
            return cos(x) + x / 2;
        };

        Text slopeText{Point{100, 380}, "x/2"};
        win.attach(slopeText);

        Function f1{one, rangeMin, rangeMax, origin, resolution, scale, scale};
        Function f2{slope, rangeMin, rangeMax, origin, resolution, scale, scale};
        Function f3{square, rangeMin, rangeMax, origin, resolution, scale, scale};
        Function f4{cos, rangeMin, rangeMax, origin, resolution, scale, scale};
        f4.set_color(Color::blue);
        Function f5(sloping_cos, rangeMin, rangeMax, origin, resolution, scale, scale);

        win.attach(f1);
        win.attach(f2);
        win.attach(f3);
        win.attach(f4);
        win.attach(f5);

        win.wait_for_button();
    }
    catch (exception &e)
    {
        cout << "error: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
        return 2;
    }
}