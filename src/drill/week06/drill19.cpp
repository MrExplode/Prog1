#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
struct S {
    S(T param = 0) : val(param) {}
    T& get();
    const T& get() const;
    void set(T other) { val = other; };
    void operator=(const T& value);
    private:
        T val;
};

template<class T>
T& S<T>::get() {
    return val;
}

template<class T>
const T& S<T>::get() const {
    return val;
}

template<class T>
void S<T>::operator=(const T& value){
	val = value;
}

template<typename T>
T& read_val(T& value) {
    std::cin >> value;
    // modified for ease of use (inlining function)
    return value;
}

template<class T>
ostream& operator<<(ostream& os, vector<T>& vector) {
    os << "{ ";
    for (int i = 0; i < vector.size(); i++)
        os << vector[i] << (i < vector.size() - 1 ? ", " : " ");
    return os << "}" << std::endl;
}

template<class T>
istream& operator>>(istream& is, vector<T>& vector) {
    std::cout << "vector input format: { value, value, value }" << std::endl;
    char dummy;
    if (read_val(dummy) != '{') {
        is.unget();
        return is;
    }
    for (T value; is >>value;) {
        vector.push_back(value);
        if (read_val(dummy) != ',') {
            break;
        }
    }
    return is;
}

int main() {
    S<int> def;
    S<int> iw {12};
    S<char> cw {'x'};
    S<double> dw {1.234};
    S<string> sw {"rip bozo"};
    S<vector<int>> vw {std::vector<int>{ 9, 8, 7, 6, 5 }};

    std::cout << "int wrapper:\t" << iw.get() << std::endl;
    std::cout << "char wrapper:\t" << cw.get() << std::endl;
    std::cout << "double wrapper:\t" << dw.get() << std::endl;
    std::cout << "string wrapper:\t" << sw.get() << std::endl;
    std::cout << "vector wrapper:\t" << vw.get() << std::endl;

    int i;
    iw.set(read_val(i));

    char c;
    //cw.set(read_val(c));
    cw = read_val(c);

    double d;
    dw.set(read_val(d));

    string s;
    sw.set(read_val(s));

    vector<int> v;
    vw.set(read_val(v));

    std::cout << std::endl << "updated values:" << std::endl;
    std::cout << "int wrapper:\t" << iw.get() << std::endl;
    std::cout << "char wrapper:\t" << cw.get() << std::endl;
    std::cout << "double wrapper:\t" << dw.get() << std::endl;
    std::cout << "string wrapper:\t" << sw.get() << std::endl;
    std::cout << "vector wrapper:\t" << vw.get() << std::endl;
}