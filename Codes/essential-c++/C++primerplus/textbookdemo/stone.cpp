#include <iostream>

using std::cout;

#include "stonewt.h"

void display(const Stonewt &st, int n);

int main() {
    // int 隐式转换
    Stonewt incognito = 275;
    //double 隐式转换
    Stonewt wolfe(285.7);


    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();

    //通过构造器进行转换
    incognito = 276.8;
    taft = 325;

    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();

    cout << "After dinner, the celebrity weighed ";
    taft.show_lbs();

    display(taft, 2);
    cout << "The wrestler weighed even more\n";
    display(422, 2);
    cout << "No stone left unearned\n";
    return 0;
}

void display(const Stonewt &st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
}