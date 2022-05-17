#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <numeric>

using namespace std;

// iterating on a map
template<typename K, typename V>
void print(const std::map<K, V>& map) {
    // std::pair<K, V>
    for (const auto& e : map) {
        std::cout << e.first << "\t" << e.second << std::endl;
    }
}

void read(std::map<string, int>& map) {
    string key;
    int value;
    std::cin >> key >> value;
    map[key] = value;
}

int main() {
    try {
        std::map<string, int> msi;
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

        //msi.erase(msi.begin(), msi.end());
        msi.clear();

        std::cout << std::endl << "Define 10 key value pairs" << std::endl;
        for (int i = 0; i < 10; i++)
            read(msi);

        print(msi);
        
        //int sum = 0;
        //for (const auto& e : msi)
        //    sum += e.second;
        int sum = std::accumulate(std::begin(msi), std::end(msi), 0, [](const int previous, const std::pair<string, int>& current){ return previous + current.second;});
        std::cout << "Sum of elements: " << sum << std::endl;

        std::map<int, string> mis;
        for (const auto& e : msi)
            mis[e.second] = e.first;

        std::cout << "mis map: " << std::endl;
        print(mis);
    } catch (exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "unknown exception!" << std::endl;
    }
}