/*
    Class definition recap
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Person {
    private:
        string fn;
        string sn;
        int a;
    public:
        Person(){}
        Person(string first_name, string second_name, int age): fn(first_name), sn(second_name), a(age) {
            // age check
            if (a < 0 || a > 150)
                throw runtime_error("invalid age");

            // name check
            string invalid[] = {";", ":", "\"", "\'", "[", "]", "*", "&", "^", "%", "$", "@", "!"};
            for (int i = 0; i < 13; i++) {
                if (fn.find(invalid[i]) != string::npos || sn.find(invalid[i]) != string::npos)
                    throw runtime_error("invalid name");  
            }
        };
        string first_name() const { return fn; }
        string second_name() const {return sn; }
        int age() const { return a; }
};

ostream& operator<<(ostream& os, const Person& p) {
    return os << p.first_name() << " " << p.second_name() << " " << p.age();
}

istream& operator>>(istream& is, Person& p) {
    string first_name;
    string second_name;
    int age;
    is >> first_name >> second_name >> age;
    p = Person(first_name, second_name, age);
    return is;
}

int main() {
    Person p = Person("Sanyika", "Lakatos", 12);
    cout << p.first_name() << " " << p.second_name() << " " << p.age() << endl;
    cout << p << endl;
    Person p2;
    cin >> p2;
    cout << p2 << endl;

    vector<Person> vec;
    for (Person p; cin >> p;) {
        if (p.first_name() == "end") break;
        vec.push_back(p);
    }

    for (auto person : vec) {
        cout << person << endl;
    }
}