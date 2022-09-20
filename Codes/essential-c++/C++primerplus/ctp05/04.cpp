#include <iostream>
#include <cmath>
const int INIT_MONEY = 100;
int main() {
    using namespace std;
    double danli = INIT_MONEY;
    double fuli = INIT_MONEY;
    int year = 0;
    while (fuli <= danli) {
        danli = 100 + year * 0.1 * 100;
        fuli = 100 * pow(1.05, year);
        year++;
    }
    cout << "经过 " << --year << " 年，复利超过单利" << endl;
    return 0;
}