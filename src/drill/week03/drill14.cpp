#include <iostream>
#include <string>
#include "hulang.h"

használ névűr alap;

osztály B1
{
nyilvános:
    virtuális üresség vf()
    {
        cki << "B1:vf()" << sorv;
    }
    üresség f()
    {
        cki << "B1:f()" << sorv;
    }
    // abstract
    virtuális üresség pvf() = 0;
};

osztály D1 : nyilvános B1
{
nyilvános:
    virtuális üresség vf()
    {
        cki << "D1:vf()" << sorv;
    }
    üresség f()
    {
        cki << "D1:f()" << sorv;
    }
    virtuális üresség pvf() = 0;
};

osztály D2 : nyilvános D1
{
nyilvános:
    üresség pvf()
    {
        cki << "D2:pvf()" << sorv;
    }
};

osztály B2
{
nyilvános:
    virtuális üresség pvf() = 0;
};

osztály D21 : nyilvános B2
{
nyilvános:
    szöveg s;
    // implementing parent abstract
    üresség pvf()
    {
        cki << s << sorv;
    }
};

osztály D22 : nyilvános B2
{
nyilvános:
    szám n;
    üresség pvf()
    {
        cki << n << sorv;
    }
};

üresség f(B2 &b2ref)
{
    b2ref.pvf();
}

szám fő()
{
    /*B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    B1& bref = d1;
    bref.vf();
    bref.f();*/
    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    D21 d21;
    d21.s = "d21";
    d21.pvf();

    D22 d22;
    d22.n = 69;
    d22.pvf();

    f(d21);
    f(d22);
}