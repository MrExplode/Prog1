#include <iostream>
#include <string>
#include <vector>
#include "hulang.h"

használ névűr alap;

minta<osztály T>
struktúra S {
    S(T param = 0) : val(param) {}
    T& get();
    állandó T& get() állandó;
    üresség set(T other) { val = other; };
    üresség kezelő=(állandó T& value);
    privát:
        T val;
};

minta<osztály T>
T& S<T>::get() {
    visszaad val;
}

minta<osztály T>
állandó T& S<T>::get() állandó {
    visszaad val;
}

minta<osztály T>
üresség S<T>::kezelő=(állandó T& value){
	val = value;
}

minta<típusnév T>
T& read_val(T& value) {
    alap::cbe >> value;
    // modified for ease of use (inlining function)
    visszaad value;
}

minta<osztály T>
kifolyam& kezelő<<(kifolyam& os, vektor<T>& vector) {
    os << "{ ";
    mert (szám i = 0; i < vector.méret(); i++)
        os << vector[i] << (i < vector.méret() - 1 ? ", " : " ");
    visszaad os << "}" << alap::sorv;
}

minta<osztály T>
befolyam& operator>>(befolyam& is, vektor<T>& vector) {
    alap::cki << "vektor bejövetel formátum: { érték, érték, érték }" << alap::sorv;
    karakter dummy;
    ha (read_val(dummy) != '{') {
        is.unget();
        visszaad is;
    }
    mert (T value; is >>value;) {
        vector.push_back(value);
        ha (read_val(dummy) != ',') {
            read_val(dummy);
            eltör;
        }
    }
    visszaad is;
}

szám fő() {
    S<szám> def;
    S<szám> iw {12};
    S<karakter> cw {'x'};
    S<tört> dw {1.234};
    S<szöveg> sw {"rip bozo"};
    S<vektor<szám>> vw {alap::vektor<szám>{ 9, 8, 7, 6, 5 }};

    alap::cki << "szám csomagoló:\t" << iw.get() << alap::sorv;
    alap::cki << "karakter csomagoló:\t" << cw.get() << alap::sorv;
    alap::cki << "tört csomagoló:\t" << dw.get() << alap::sorv;
    alap::cki << "szöveg csomagoló:\t" << sw.get() << alap::sorv;
    alap::cki << "vektor csomagoló:\t" << vw.get() << alap::sorv;

    szám i;
    iw.set(read_val(i));

    karakter c;
    //cw.set(read_val(c));
    cw = read_val(c);

    tört d;
    dw.set(read_val(d));

    szöveg s;
    sw.set(read_val(s));

    vektor<szám> v;
    vw.set(read_val(v));

    alap::cki << alap::sorv << "frissített értékek:" << alap::sorv;
    alap::cki << "szám csomagoló:\t" << iw.get() << alap::sorv;
    alap::cki << "karakter csomagoló:\t" << cw.get() << alap::sorv;
    alap::cki << "tört csomagoló:\t" << dw.get() << alap::sorv;
    alap::cki << "szöveg csomagoló:\t" << sw.get() << alap::sorv;
    alap::cki << "vektor csomagoló:\t" << vw.get() << alap::sorv;
}