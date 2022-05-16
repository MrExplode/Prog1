#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Item {
    string name;
    int iid;
    double value;
    Item() : name("unknown"), iid(-1), value(0) {}
    Item(string n, int id, double v) : name(n), iid(id), value(v) {}
};

ostream& operator<<(ostream& os, const Item& item) {
    return os << "{ " << item.name << " " << item.iid << " " << item.value << " }" << std::endl;
}

istream& operator>>(istream& is, Item& item) {
    char dummy;
    is >> dummy;
    if (dummy != '{') {
        is.unget();
        return is;
    }
    is >> item.name >> item.iid >> item.value;
    return is;
}

struct by_name {
    bool operator()(const Item& a, const Item& b) const {
        return a.name < b.name;
    }
};

struct by_id {
    bool operator()(const Item& a, const Item& b) const {
        return a.iid < b.iid;
    }
};

struct by_value {
    bool operator()(const Item& a, const Item& b) const {
        return a.value > b.value;
    }
};

int main() {
    vector<Item> vi;
    ifstream fileIn {"data.txt"};
    for (int i = 0; i < 10; i++) {
        Item item;
        fileIn >> item;
        vi.push_back(item);
    }

    // sort with struct as predicate
    std::sort(vi.begin(), vi.end(), by_name());

    std::sort(vi.begin(), vi.end(), by_id());

    std::sort(vi.begin(), vi.end(), by_value());

    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    // see
    // https://stackoverflow.com/a/16013546
    // and
    // https://stackoverflow.com/a/9053941
    auto it = std::remove_if(vi.begin(), vi.end(), [](const Item& item) { return item.name == "apple" || item.name == "banana"; });
    vi.erase(it);

    vi.erase(std::remove_if(vi.begin(), vi.end(), [](const Item& item) { return item.iid == 10 || item.iid == 12; }));

    list<Item> li(vi.begin(), vi.end());

        // sort with lambda as predicate
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });

    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });

    li.sort([](const Item& a, const Item& b) { return a.value < b.value; });

    li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});

    li.remove_if([](const Item& item) { return item.name == "apple" || item.name == "banana"; });

    li.remove_if([](const Item& item) { return item.iid == 10 || item.iid == 12; });
}