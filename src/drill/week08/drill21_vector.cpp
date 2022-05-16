#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include "hulang.h"

használ névűr alap;

minta<osztály T>
kifolyam& kezelő<<(kifolyam& os, vektor<T>& vector) {
    os << "{ ";
    mert (állandó auto& e : vector)
        os << e << " ";
    os << "}";
    visszaad os;
}

szám fő() {
    vektor<tört> vd;
    beffolyam fileIn {"data2.txt"};
    tört value;
    miközben (fileIn >> value)
        vd.nyom_hátra(value);
    
    alap::cki << vd << alap::sorv;

    vektor<szám> vi (vd.méret());
    alap::copy(vd.kezd(), vd.vég(), vi.kezd());

    alap::cki << "párok: " << alap::sorv;
    mert (szám i = 0; i < vd.méret(); i++)
        alap::cki << vd[i] << "\t: " << vi[i] << alap::sorv;

    tört doubleSum = alap::felhalmoz(vd.kezd(), vd.vég(), 0.0);
    alap::cki << alap::sorv << "tört vektor összege: " << doubleSum << alap::sorv << alap::sorv;

    szám számSum = alap::felhalmoz(vi.kezd(), vi.vég(), 0);
    tört diff_sum = alap::belső_termék(vd.kezd(), vd.vég(), vi.kezd(), 0.0, alap::összead<tört>(), alap::kivon<tört>());
    alap::cki << "összegek különbsége: " << (doubleSum - számSum) << " " << diff_sum << alap::sorv << alap::sorv;

    alap::megfordít(vd.kezd(), vd.vég());
    alap::cki << "megfordított tört vektor: " << vd << alap::sorv << alap::sorv;

    tört vdMean = doubleSum / vd.méret();
    alap::cki << "tö9rt vektor átlag: " << vdMean << alap::sorv << alap::sorv;

    vektor<tört> vd2;
    auto it = alap::copy_if(vd.kezd(), vd.vég(), alap::hátra_szúró(vd2), [vdMean](tört value) { visszaad value < vdMean; });
    alap::cki << "Values below mean: " << vd2 << alap::sorv << alap::sorv;

    alap::sorbarendez(vd.kezd(), vd.vég());
    alap::cki << "Sorted double array: " << vd << alap::sorv;
}