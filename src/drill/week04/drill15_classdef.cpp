#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "hulang.h"

használ névűr alap;

osztály Person
{
privát:
    szöveg fn;
    szöveg sn;
    szám a;

nyilvános:
    Person() {}
    Person(szöveg first_name, szöveg second_name, szám age) : fn(first_name), sn(second_name), a(age)
    {
        // age check
        ha (a < 0 || a > 150)
            dob futóidő_hiba("invalid age");

        // name check
        szöveg invalid[] = {";", ":", "\"", "\'", "[", "]", "*", "&", "^", "%", "$", "@", "!"};
        mert (szám i = 0; i < 13; i++)
        {
            if (fn.talál(invalid[i]) != szöveg::npos || sn.talál(invalid[i]) != szöveg::npos)
                dob futóidő_hiba("invalid name");
        }
    };
    szöveg first_name() állandó { visszaad fn; }
    szöveg second_name() állandó { visszaad sn; }
    szám age() állandó { visszaad a; }
};

kifolyam &kezelő<<(kifolyam &os, const Person &p)
{
    visszaad os << p.first_name() << " " << p.second_name() << " " << p.age();
}

befolyam &kezelő>>(befolyam &is, Person &p)
{
    szöveg first_name;
    szöveg second_name;
    szám age;
    is >> first_name >> second_name >> age;
    p = Person(first_name, second_name, age);
    visszaad is;
}

szám fő()
{
    Person p = Person("Goofy", "Goo", 63);
    cki << p.first_name() << " " << p.second_name() << " " << p.age() << sorv;
    cki << p << sorv;
    Person p2;
    cbe >> p2;
    cki << p2 << sorv;

    vektor<Person> vec;
    mert (Person p; cbe >> p;)
    {
        ha (p.first_name() == "end")
            eltör;
        vec.nyom_hátra(p);
    }

    mert (auto person : vec)
    {
        cki << person << sorv;
    }
}