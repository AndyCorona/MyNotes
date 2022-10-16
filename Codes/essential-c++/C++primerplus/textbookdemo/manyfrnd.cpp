#include <iostream>

using std::cout;
using std::endl;


template<typename T>
class ManyFriend {
private:
    T item;
public:
    ManyFriend(const T &i) : item(i) {};

    template<typename C, typename D>
    friend void show2(C &, D &);
};

template<typename C, typename D>
void show2(C &c, D &d) {
    cout << c.item << " " << d.item << endl;
}

int main() {
    ManyFriend<int> hfint1(10);
    ManyFriend<int> hfint2(20);
    ManyFriend<double> hfdouble(10.5);
    cout << "hfint1, hfint2: ";
    show2(hfint1, hfint2);
    cout << "hfdouble, hfint1: ";
    show2(hfdouble, hfint2);
    return 0;
};


