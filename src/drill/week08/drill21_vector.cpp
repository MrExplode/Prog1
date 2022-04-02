#include <iostream>
#include <string>
#include <vector>
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


// copy only the elements that match the predicate
template<class T>
void copy_if(vector<T>& from, vector<T>& to, std::function<bool(T)> predicate) {
    for (const auto& e : from) {
        if (predicate(e))
            to.push_back(e);
    }
}

int main() {
    vector<double> vd;
    // fancy random values
    for (int i = 0; i < 16; i++)
        vd.push_back((std::rand() % 150) / (double)3);
    
    std::cout << vd << std::endl;

    vector<int> vi;
    for (double d : vd)
        vi.push_back(d);

    std::cout << "pairs of elements: " << std::endl;
    for (int i = 0; i < vd.size(); i++)
        std::cout << vd[i] << "\t: " << vi[i] << std::endl;

    double doubleSum = 0;
    for (double d : vd)
        doubleSum += d;
    std::cout << std::endl << "Sum of double vector: " << doubleSum << std::endl << std::endl;

    int intSum = 0;
    for (int i : vi)
        intSum += i;
    std::cout << "Difference of sums: " << (doubleSum - intSum) << std::endl << std::endl;

    std::reverse(vd.begin(), vd.end());
    std::cout << "Reverse double vector: " << vd << std::endl << std::endl;

    double vdMean = doubleSum / vd.size();
    std::cout << "Double vector mean: " << vdMean << std::endl << std::endl;

    vector<double> vd2;
    // cursed stuff, don't look!
    const double meanConst = vdMean;
    copy_if(vd, vd2, static_cast<std::function<bool(double)>>([meanConst](double element){ return element < meanConst;}));
    std::cout << "Values below mean: " << vd2 << std::endl << std::endl;

    std::sort(vd.begin(), vd.end());
    std::cout << "Sorted double array: " << vd << std::endl;
}