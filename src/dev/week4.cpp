/*
    functional programming
*/

#include "../gui/std_lib_facilities.h"

int main() {
    // [] lambda introducer
    // () argument list
    // {} function body

    // []
    // [&] capture by reference
    // [=] capture by value
    // [&A, =B] capture A by ref, B by value
    // [=, &A] everything by value, except

    // anonym lambda
    [](){
        cout << "Hello c++ lambda!" << endl;
    }();

    // named lambda
    auto sum = [](double A, double B) {
        return A + B;
    };
    auto add = sum;

    cout << sum(5, 2) << endl;
    cout << add(4.20, 6.9) << endl;

    // return type (recommended usage)
    auto add2 = [](double A, double B) -> double {
        return A + B;
    };
    cout << add2(4.20, 6.9) << endl;

    // capturing variables
    double pi = 3.1416;
    auto func = [pi]() {
        cout << "Value of pi: " << pi << endl;
    };
    func();

    auto genericLambda = [](auto arg) {
        return arg + arg;
    };
    cout << genericLambda(5) << endl;
    cout << genericLambda(3.1416) << endl;
}