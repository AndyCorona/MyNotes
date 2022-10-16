#include <iostream>

using std::cout;
using std::endl;

template<typename T>
void counts();

template<typename T>
void reports(T &);


template<typename TT>
class HasFriend {
private:
    TT item;
    static int ct;
public:
    HasFriend(const TT &i) : item(i) { ct++; }

    ~HasFriend() { ct--; }

    friend void counts<TT>();

    friend void reports<>(HasFriend<TT> &);
};

template<typename T>
int HasFriend<T>::ct = 0;

template<typename T>
void counts() {
    cout << "template size: " << sizeof(HasFriend<T>) << "; ";
    cout << "template counts(): " << HasFriend<T>::ct << endl;
}


template<typename T>
void reports(T &hf) {
    cout << hf.item << endl;
}


int main() {

    counts<int>();
    HasFriend<int> hfint1(10);
    HasFriend<int> hfint2(20);
    HasFriend<double> hfdouble(10.5);
    reports(hfint1);
    reports(hfint2);
    reports(hfdouble);

    cout << "counts<int> output:\n";
    counts<int>();
    cout << "counts<double> output:\n";
    counts<double>();

    return 0;
}