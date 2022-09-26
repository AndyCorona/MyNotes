#include <iostream>
#include <cstring>

struct stringy {
    char *str;
    int ct;
};
using namespace std;

void show(const char *, int  = 1);

void show(const stringy &, int  = 1);

void set(stringy &, char *);

int main() {
    stringy beany;
    char testing[] = "reality isn't what it used to be";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}

void show(const char *str, int n) {
    for (int i = 0; i < n; i++) {
        cout << str;
        cout << endl;
    }
}

void show(const stringy &str, int n) {
    for (int i = 0; i < n; i++) {
        cout << str.str;
        cout << endl;
    }
}

void set(stringy &str, char *st) {
    char *temp = new char[sizeof(st)];
    str.str = temp;
    strcpy(str.str, st);
    str.ct = 10;
}