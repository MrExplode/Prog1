#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, vector<T>& vector) {
    os << "{ ";
    for (const auto& e : vector)
        os << e << " ";
    os << "}";
    return os;
}

int main() {
    vector<double> vd;
    ifstream fileIn {"data2.txt"};
    double value;
    while (fileIn >> value)
        vd.push_back(value);
    
    std::cout << vd << std::endl;

    vector<int> vi (vd.size());
    //for (double d : vd)
    //    vi.push_back(d);
    std::copy(vd.begin(), vd.end(), vi.begin());

    std::cout << "pairs of elements: " << std::endl;
    for (int i = 0; i < vd.size(); i++)
        std::cout << vd[i] << "\t: " << vi[i] << std::endl;

    double doubleSum = std::accumulate(vd.begin(), vd.end(), 0.0);
    //for (double d : vd)
    //    doubleSum += d;
    std::cout << std::endl << "Sum of double vector: " << doubleSum << std::endl << std::endl;

    int intSum = std::accumulate(vi.begin(), vi.end(), 0);
    //for (int i : vi)
    //    intSum += i;
    double diff_sum = std::inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, std::plus<double>(), std::minus<double>());
    std::cout << "Difference of sums: " << (doubleSum - intSum) << " " << diff_sum << std::endl << std::endl;

    std::reverse(vd.begin(), vd.end());
    std::cout << "Reverse double vector: " << vd << std::endl << std::endl;

    double vdMean = doubleSum / vd.size();
    std::cout << "Double vector mean: " << vdMean << std::endl << std::endl;

    vector<double> vd2;
    auto it = std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2), [vdMean](double value) { return value < vdMean; });
    std::cout << "Values below mean: " << vd2 << std::endl << std::endl;

    std::sort(vd.begin(), vd.end());
    std::cout << "Sorted double array: " << vd << std::endl;
}