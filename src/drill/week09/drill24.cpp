#include <iostream>
#include <complex>
#include <numeric>
#include <string>
#include <cmath>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

void takeSqrt() {
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    if (a < 0)
        std::cout << "no square root" << std::endl;
    else
        std::cout << "square root: " << std::sqrt(a) << std::endl;
}

int main() {
    std::cout << "Size of char:\t"    << sizeof(char)    << std::endl;
    std::cout << "Size of short:\t"   << sizeof(short)   << std::endl;
    std::cout << "Size of int:\t"     << sizeof(int)     << std::endl;
    std::cout << "Size of long:\t"    << sizeof(long)    << std::endl;
    std::cout << "Size of float:\t"   << sizeof(float)   << std::endl;
    std::cout << "Size of double:\t"  << sizeof(double)  << std::endl;
    std::cout << "Size of int*:\t"    << sizeof(int*)    << std::endl;
    std::cout << "Size of double*: "  << sizeof(double*) << std::endl;
    std::cout << std::endl;

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int, 2> d(10, 10);
    Matrix<int, 3> e(10, 10, 10);

    std::cout << "Size of a: " << sizeof(a) << std::endl;
    std::cout << "Size of b: " << sizeof(b) << std::endl;
    std::cout << "Size of c: " << sizeof(c) << std::endl;
    std::cout << "Size of d: " << sizeof(d) << std::endl;
    std::cout << "Size of e: " << sizeof(e) << std::endl;
    std::cout << std::endl;

    std::cout << "Elements in a: " << a.size() << std::endl;
    std::cout << "Elements in b: " << b.size() << std::endl;
    std::cout << "Elements in c: " << c.size() << std::endl;
    std::cout << "Elements in d: " << d.size() << std::endl;
    std::cout << "Elements in e: " << e.size() << std::endl;
    std::cout << std::endl;

    takeSqrt();
    std::cout << std::endl;

    std::cout << "Enter 10 floating point numbers" << std::endl;
    Matrix<double> doubles(10);
    for (int i = 0; i < 10; i++)
        std::cin >> doubles[i];
    std::cout << "Matrix: " << doubles << std::endl;
    std::cout << std::endl;

    std::cout << "Dimensions of multiplication table:" << std::endl;
    int n;
    int m;
    std::cin >> n >> m;
    Matrix<int, 2> table(n+1, m+1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            table[i][j] = i * j;
            std::cout << table(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Enter ten complex numbers:" << std::endl;
    Matrix<std::complex<double>> cmatrix(10);
    std::complex<double> input;
    for (int i = 0; i < 10; i++) {
        std::cin >> input;
        cmatrix(i) = input;
    }
    auto sum = std::accumulate(cmatrix.data(), cmatrix.data() + cmatrix.size(), std::complex<double>{});
    std::cout << "Sum: " << sum << std::endl << std::endl;

    std::cout << "Enter six integers:" << std::endl;
    Matrix<int, 2> m2(2, 3);
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 3; j++)
            std::cin >> m2[i][j];
    std::cout << "Matrix: " << m2 << std::endl;
}