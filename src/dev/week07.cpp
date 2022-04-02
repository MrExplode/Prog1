/*
    Collections - List, Array
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

template<class T>
void printContents(T container) {
    std::for_each(container.begin(), container.end(), [](int param){std::cout << param << " ";});
    std::cout << std::endl;
}

template<typename T>
void printContents2(const T& container) {
    for (auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template<class T>
void increment(T& container, int amount) {
    for (auto& element : container)
        element += amount;
}

template<class I, class O>
O custom_copy(I start, I end, O target) {
    for (I p = start; p != end; ++p) {
        *target++ = *p;
    }
    return target;
}


int main() {
    constexpr int size = 10;
    int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    std::array<int, size> ai;
    std::copy(nums, nums + size, ai.begin());

    std::vector<int> vi(size);
    std::copy(nums, nums + size, vi.begin());

    std::list<int> li(size);
    std::copy(nums, nums + size, li.begin());

    cout << "array: " << endl;
    printContents(ai);
    cout << "vector: " << endl;
    printContents(vi);
    cout << "list: " << endl;
    printContents(li);

    // clones
    std::array<int, size> aClone = ai;
    std::vector<int> vClone = vi;
    std::list<int> lClone = li;

    cout << "clones: " << endl;
    printContents2(aClone);
    printContents2(vClone);
    printContents2(lClone);
    cout << endl;

    increment(aClone, 2);
    increment(vClone, 3);
    increment(lClone, 5);

    cout << "increments: " << endl;
    printContents2(aClone);
    printContents2(vClone);
    printContents2(lClone);
    cout << endl;

    // using our copy function
    std::vector<int> dummy(size);
    custom_copy(aClone.begin(), aClone.end(), dummy.begin());
    cout << "custom copy: ";
    printContents2(dummy);
    cout << endl;

    // search for element
    int searched = 3;
    std::vector<int>::iterator vit;
    vit = std::find(dummy.begin(), dummy.end(), searched);
    if (vit != dummy.end()) {
        cout << "Found " << searched << " on index: " << std::distance(dummy.begin(), vit) << endl;
    } else {
        cout << searched << " not found" << endl;
    }
}