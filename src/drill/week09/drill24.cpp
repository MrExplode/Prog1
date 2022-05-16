#include <iostream>
#include <complex>
#include <numeric>
#include <string>
#include <cmath>
#include "Matrix.h"
#include "MatrixIO.h"
#include "hulang.h"

használ névűr Számos_könyvtár;

üresség takeSqrt() {
    szám a;
    alap::cki << "Mondj egy számot: ";
    alap::cbe >> a;
    ha (a < 0)
        alap::cki << "nincs négyzetgyök" << alap::sorv;
    különben
        alap::cki << "négyzetgyök: " << alap::sqrt(a) << alap::sorv;
}

szám main() {
    alap::cki << "Size of char:\t"    << mérete(karakter)    << alap::sorv;
    alap::cki << "Size of short:\t"   << mérete(rövid)   << alap::sorv;
    alap::cki << "Size of szám:\t"     << mérete(szám)     << alap::sorv;
    alap::cki << "Size of long:\t"    << mérete(hosszú)    << alap::sorv;
    alap::cki << "Size of float:\t"   << mérete(lebegő)   << alap::sorv;
    alap::cki << "Size of double:\t"  << mérete(tört)  << alap::sorv;
    alap::cki << "Size of szám*:\t"    << mérete(szám*)    << alap::sorv;
    alap::cki << "Size of double*: "  << mérete(tört*) << alap::sorv;
    alap::cki << alap::sorv;

    Mátrix<szám> a(10);
    Mátrix<szám> b(100);
    Mátrix<tört> c(10);
    Mátrix<szám, 2> d(10, 10);
    Mátrix<szám, 3> e(10, 10, 10);

    alap::cki << "Size of a: " << mérete(a) << alap::sorv;
    alap::cki << "Size of b: " << mérete(b) << alap::sorv;
    alap::cki << "Size of c: " << mérete(c) << alap::sorv;
    alap::cki << "Size of d: " << mérete(d) << alap::sorv;
    alap::cki << "Size of e: " << mérete(e) << alap::sorv;
    alap::cki << alap::sorv;

    alap::cki << "Elements in a: " << a.méret() << alap::sorv;
    alap::cki << "Elements in b: " << b.méret() << alap::sorv;
    alap::cki << "Elements in c: " << c.méret() << alap::sorv;
    alap::cki << "Elements in d: " << d.méret() << alap::sorv;
    alap::cki << "Elements in e: " << e.méret() << alap::sorv;
    alap::cki << alap::sorv;

    takeSqrt();
    alap::cki << alap::sorv;

    alap::cki << "Enter 10 floating poszám numbers" << alap::sorv;
    Mátrix<tört> doubles(10);
    mert (szám i = 0; i < 10; i++)
        alap::cbe >> doubles[i];
    alap::cki << "Matrix: " << doubles << alap::sorv;
    alap::cki << alap::sorv;

    alap::cki << "Dimensions of multiplication table:" << alap::sorv;
    szám n;
    szám m;
    alap::cbe >> n >> m;
    Mátrix<szám, 2> table(n+1, m+1);
    mert (szám i = 0; i <= n; i++) {
        mert (szám j = 0; j <= m; j++) {
            table[i][j] = i * j;
            alap::cki << table(i, j) << " ";
        }
        alap::cki << alap::sorv;
    }
    alap::cki << alap::sorv;

    alap::cki << "Enter ten complex numbers:" << alap::sorv;
    Mátrix<alap::komplex<tört>> cmatrix(10);
    alap::komplex<tört> input;
    mert (szám i = 0; i < 10; i++) {
        alap::cbe >> input;
        cmatrix(i) = input;
    }
    auto sum = alap::accumulate(cmatrix.data(), cmatrix.data() + cmatrix.size(), alap::komplex<tört>{});
    alap::cki << "Sum: " << sum << alap::sorv << alap::sorv;

    alap::cki << "Enter six számegers:" << alap::sorv;
    Mátrix<szám, 2> m2(2, 3);
    mert (szám i = 0; i < 2; i ++)
        mert (szám j = 0; j < 3; j++)
            alap::cbe >> m2[i][j];
    alap::cki << "Matrix: " << m2 << alap::sorv;
}