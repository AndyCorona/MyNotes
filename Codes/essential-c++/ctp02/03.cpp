#include <iostream>

using namespace std;

extern bool fibon_elem(int, int &);

int main() {
    int pos, elem;
    char ch;
    bool more = true;
    while (more) {
        cout << "Please enter a position:";
        cin >> pos;
        if (fibon_elem(pos, elem)) {
            cout << "element # " << pos << " is " << elem << endl;
        } else {
            cout << "Sorry, Could not calculate element # ";
        }
        cout << "Would you like to try again? (y/n)";
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            more = false;
        }
    }
    return 0;
}

/*
 * 实现斐波那契数列
 */
bool fibon_elem(int pos, int &elem) {
    //检查值是否在合理区间
    if (pos <= 0 || pos > 1024) {
        elem = 0;
        return false;
    }
    elem = 1;
    int n2 = 1, n1 = 1;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n1 + n2;
        n2 = n1;
        n1 = elem;
    }
    return true;
}


