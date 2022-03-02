/*
    Different ways to do x + y by functional programming
*/

#include <iostream>
#include <functional>

using namespace std;

int sum(int x, int y) {
    return x + y;
}

class Add {
    public:
        int operator() (int x, int y) const {
            return x + y;
        }
};

struct add_x {
    add_x(int val) : x(val) {}
    int operator() (int y) const {
        return x + y;
    }
    private:
        int x;
};

int main() {
    // funktor xd
    add_x add (42);
    int i = add(8);
    cout << i << endl;
    i = add(9);
    cout << i << endl;

    // generic
    function<int(int, int)> func;
    // using classic functions as generic lambdas (?)
    func = sum;
    cout << func(5, 7) << endl;

    // lambda definition with generic (the auto keyword is just hiding the long type tho)
    std::function<double(double, double)> sum2 = [](double A, double B) {
        return A + B;
    };
    cout << sum2(4.6, 5.9) << endl;
}