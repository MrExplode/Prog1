#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include "hulang.h"

használ névűr alap;

minta<típusnév K, típusnév V>
üresség print(állandó alap::térkép<K, V>& map) {
    mert (állandó auto& e : map) {
        alap::cki << e.első << "\t" << e.második << alap::sorv;
    }
}

üresség read(alap::térkép<szöveg, szám>& map) {
    szöveg key;
    szám value;
    alap::cbe >> key >> value;
    map[key] = value;
}

szám fő() {
    próbál {
        alap::térkép<szöveg, szám> msi;
        msi["asd"] = 1;
        msi["b"] = 12;
        msi["cd"] = 17;
        msi["dd"] = 6;
        msi["e"] = 18;
        msi["fgh"] = 123;
        msi["g"] = 9;
        msi["hello"] = 8;
        msi["xd"] = 7;
        msi["jk"] = 10;

        print(msi);

        msi.tisztít();

        alap::cki << alap::sorv << "Adj 10 kulcs érték párt" << alap::sorv;
        mert (szám i = 0; i < 10; i++)
            read(msi);

        print(msi);
        
        //int sum = 0;
        //for (const auto& e : msi)
        //    sum += e.second;
        szám sum = alap::felhalmoz(alap::kezd(msi), alap::vég(msi), 0, [](állandó szám previous, állandó alap::pár<szöveg, szám>& current){ visszaad previous + current.második;});
        alap::cki << "Tagok összege: " << sum << alap::sorv;

        alap::térkép<szám, szöveg> mis;
        mert (állandó auto& e : msi)
            mis[e.second] = e.first;

        alap::cki << "mis térkép: " << alap::sorv;
        print(mis);
    } elkap (kivétel& e) {
        alap::chiba << "kivétel: " << e.mi() << alap::sorv;
    } elkap (...) {
        alap::chiba << "ismeretlen kivétel!" << alap::sorv;
    }
}