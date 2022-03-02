/*
    Pure functions
*/

#include <iostream>
#include <cmath>

using namespace std;

double absolute(double n) {
    // ˘˘ mellékhatás
    cout << "abszolútérték előtt: " << n << endl;
    return abs(n);
}

int main() {
    cout << abs(0.25) << endl;
    cout << absolute(0.025) << endl;
}