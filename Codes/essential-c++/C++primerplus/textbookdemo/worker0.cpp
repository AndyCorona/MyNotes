#include <iostream>
#include "worker0.h"

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Set() {
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n') {
        continue;
    }
}

void Worker::Show() const {
    cout << "Name: " << fullname << endl;
    cout << "Id: " << id << endl;
}

void Waiter::Set() {
    Worker::Set();
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n') {
        continue;
    }
}

void Waiter::Show() const {
    cout << "Category: waiter \n";
    Worker::Show();
    cout << "Panache rating: " << panache << endl;
}


char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set() {
    Worker::Set();
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++) {
        cout << i << ": " << pv[i] << endl;
        if (i % 4 == 3) {
            cout << endl;
        }
        if (i % 4 != 0) {
            cout << endl;
        }
        while (cin >> voice && (voice < 0 || voice >= Vtypes)) {
            cout << "Please Enter a value <=0 and < " << Vtypes << endl;
        }
        while (cin.get() != '\0') {
            continue;
        }
    }
}

void Singer::Show() const {
    cout << "Category: singer\n";
    Worker::Show();
    cout << "Vocal range: " << pv[voice] << endl;
}
