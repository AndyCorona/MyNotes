#include <iostream>

const int SIZE = 3;
const int strsize = 20;
using namespace std;
struct bop {
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

void showmenu();

void show_by_name(const bop *ptr);

void show_by_title(const bop *ptr);

void show_by_bopname(const bop *ptr);

void show_by_preference(const bop *ptr);

int main() {
    //初始化信息
    bop ptr[SIZE] = {
            {"a1", "b2", "c1",0},
            {"a2", "b2", "c2",1},
            {"a3", "b3", "c3",2},
    };
    //初始化主界面
    showmenu();
    cout << "Enter your choice: ";
    char ch;
    cin >> ch;
    while (ch != 'q') {
        switch (ch) {
            case 'a':
                show_by_name(ptr);
                break;
            case 'b':
                show_by_title(ptr);
                break;
            case 'c':
                show_by_bopname(ptr);
                break;
            case 'd':
                show_by_preference(ptr);
                break;
        }
        cout << "Next choice:";
        cin >> ch;
    }
    cout << "Bye!" << endl;
    return 0;
}

void showmenu() {
    cout << "Benevolent Order of Programmers Report\n";
    cout << "a. display by name             b. display by title\n";
    cout << "c. display by bopname          d. display by preference\n";
    cout << "q. quit" << endl;
}

void show_by_name(const bop *ptr) {
    for (int i = 0; i < SIZE; i++) {
        cout << ptr[i].fullname << endl;
    }
}

void show_by_title(const bop *ptr) {
    for (int i = 0; i < SIZE; i++) {
        cout << ptr[i].title << endl;
    }
}

void show_by_bopname(const bop *ptr) {
    for (int i = 0; i < SIZE; i++) {
        cout << ptr[i].bopname << endl;
    }
}

void show_by_preference(const bop *ptr) {
    for (int i = 0; i < SIZE; i++) {
        cout << ptr[i].preference << endl;
    }
}
