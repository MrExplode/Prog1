#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include "hulang.h"

használ névűr alap;

minta<osztály T>
üresség printContents(T container) {
    alap::minden_egyes(container.kezd(), container.vég(), [](szám param){alap::cki << param << " ";});
    alap::cki << alap::sorv;
}

template<typename T>
void printContents2(const T& container) {
    for (auto& element : container) {
        alap::cki << element << " ";
    }
    alap::cki << alap::sorv;
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
    állandókifejez szám size = 10;
    szám nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    alap::tömb<szám, size> ai;
    alap::copy(nums, nums + size, ai.kezd());

    alap::vektor<szám> vi(size);
    alap::copy(nums, nums + size, vi.kezd());

    alap::lista<szám> li(size);
    alap::copy(nums, nums + size, li.kezd());

    alap::cki << "array: " << alap::sorv;
    printContents(ai);
    alap::cki << "vector: " << alap::sorv;
    printContents(vi);
    alap::cki << "list: " << alap::sorv;
    printContents(li);

    // clones
    alap::tömb<szám, size> aClone = ai;
    alap::vektor<szám> vClone = vi;
    alap::lista<szám> lClone = li;

    alap::cki << "klónok: " << alap::sorv;
    printContents2(aClone);
    printContents2(vClone);
    printContents2(lClone);
    alap::cki << alap::sorv;

    increment(aClone, 2);
    increment(vClone, 3);
    increment(lClone, 5);

    alap::cki << "növeltek: " << alap::sorv;
    printContents2(aClone);
    printContents2(vClone);
    printContents2(lClone);
    alap::cki << alap::sorv;

    // using our copy function
    alap::vektor<szám> dummy(size);
    custom_copy(aClone.kezd(), aClone.vég(), dummy.kezd());
    alap::cki << "egyedi másolás: ";
    printContents2(dummy);
    alap::cki << alap::sorv;

    // search for element
    szám searched = 3;
    alap::vektor<szám>::iterátor vit;
    vit = alap::talál(dummy.kezd(), dummy.vég(), searched);
    ha (vit != dummy.vég()) {
        cki << "Megtalálva " << searched << " az indexen: " << alap::távolság(dummy.kezd(), vit) << sorv;
    } különben {
        cki << searched << " nem talált xd" << sorv;
    }
}