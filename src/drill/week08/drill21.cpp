#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "hulang.h"

használ névűr alap;

struktúra Item {
    szöveg name;
    szám iid;
    tört value;
    Item() : name("unknown"), iid(-1), value(0) {}
    Item(szöveg n, szám id, tört v) : name(n), iid(id), value(v) {}
};

kifolyam& kezelő<<(kifolyam& os, állandó Item& item) {
    visszaad os << "{ " << item.name << " " << item.iid << " " << item.value << " }" << alap::sorv;
}

befolyam& kezelő>>(befolyam& is, Item& item) {
    karakter dummy;
    is >> dummy;
    ha (dummy != '{') {
        is.unget();
        visszaad is;
    }
    is >> item.name >> item.iid >> item.value;
    visszaad is;
}

struktúra by_name {
    logikai kezelő()(állandó Item& a, állandó Item& b) állandó {
        visszaad a.name < b.name;
    }
};

struktúra by_id {
    logikai kezelő()(állandó Item& a, állandó Item& b) állandó {
        visszaad a.iid < b.iid;
    }
};

struktúra by_value {
    logikai kezelő()(állandó Item& a, állandó Item& b) állandó {
        visszaad a.value > b.value;
    }
};

szám fő() {
    vektor<Item> vi;
    beffolyam fileIn {"data.txt"};
    mert (szám i = 0; i < 10; i++) {
        Item item;
        fileIn >> item;
        vi.nyom_hátra(item);
    }

    // sort with struktúra as predicate
    alap::sorbarendez(vi.kezd(), vi.vég(), by_name());

    alap::sorbarendez(vi.kezd(), vi.vég(), by_id());

    alap::sorbarendez(vi.kezd(), vi.vég(), by_value());

    vi.nyom_hátra(Item{"horse shoe", 99, 12.34});
    vi.nyom_hátra(Item{"Canon S400", 9988, 499.95});

    auto it = alap::eltávolít_ha(vi.kezd(), vi.vég(), [](állandó Item& item) { visszaad item.name == "apple" || item.name == "banana"; });
    vi.kitöröl(it);

    vi.kitöröl(alap::eltávolít_ha(vi.kezd(), vi.vég(), [](állandó Item& item) { visszaad item.iid == 10 || item.iid == 12; }));

    lista<Item> li(vi.kezd(), vi.vég());

        // sort with lambda as predicate
    li.sorbarendez([](állandó Item& a, állandó Item& b) { visszaad a.name < b.name; });

    li.sorbarendez([](állandó Item& a, állandó Item& b) { visszaad a.iid < b.iid; });

    li.sorbarendez([](állandó Item& a, állandó Item& b) { visszaad a.value < b.value; });

    li.nyom_hátra(Item{"horse shoe", 99, 12.34});
    li.nyom_hátra(Item{"Canon S400", 9988, 499.95});

    li.eltávolít_ha([](állandó Item& item) { visszaad item.name == "apple" || item.name == "banana"; });

    li.eltávolít_ha([](állandó Item& item) { visszaad item.iid == 10 || item.iid == 12; });
}