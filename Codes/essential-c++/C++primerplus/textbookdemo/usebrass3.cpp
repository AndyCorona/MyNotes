#include <iostream>
#include "acctabc.h"
#include <string>

const int CLIENTS = 4;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    AcctABC *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    long tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter 1 for Brass Account or "
             << " 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2')) {
            cout << "Enter ether 1 or 2: ";
        }
        if (kind == '1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double tmax, trate;
            cout << "Enter thr overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n') {
            continue;
        }
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++) {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++) {
        delete p_clients[i];
    }
    cout << "Done.\n";
    return 0;


    return 0;
}