/*
    Collections - Set
    (not part of the drills)
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>

struct Fruit {
    std::string name;
    int quantity;
    double unit_price;
    Fruit(const std::string& n, int q = 0, double p = 0.0) : name(n), quantity(q), unit_price(p) {}
};

// custom comparator
struct Fruit_ptr_comp {
    bool operator()(const Fruit* a, const Fruit* b) const {
        return a->name < b->name;
    }
};

int main() {
    try {
        std::vector<Fruit> vf {
            Fruit{"Plum", 3},
            Fruit{"Grape", 53},
            Fruit{"Banana", 11},
            Fruit{"Apple", 87},
            Fruit{"Orange", 23},
            Fruit{"Cherry", 15},
            Fruit{"Plum", 52},
            Fruit{"Kiwi", 61}
        };

        std::cout << "Vector of fruits:" << std::endl;
        for (const auto& fruit : vf)
            std::cout << fruit.name << std::endl;
        std::cout << std::endl;

        // using the custom sorting
        std::set<Fruit*, Fruit_ptr_comp> produce;
        for (auto& f : vf)
            produce.insert(&f);
        
        std::cout << "Set od fruits: " << std::endl;
        for (const auto& f : produce)
            std::cout << f->name << std::endl;
        std::cout << std::endl;


    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
    }
}