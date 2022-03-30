/*
    Higher order functions

    function as parameter and/or return type
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // update every element in the vector
    std::transform(v.begin(), v.end(), v.begin(), [](int n) -> int { 
            return n + (n * 2);
    });

    std::for_each(v.begin(), v.end(), [](const int& x) {
        std::cout << x << endl;
    });
}