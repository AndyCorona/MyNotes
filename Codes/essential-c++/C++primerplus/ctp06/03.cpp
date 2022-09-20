#include <iostream>

using namespace std;

void showmenu();

int main() {
    showmenu();
    char ch;
    cin >> ch;
    while (true) {
        cin >> ch;
        switch (ch) {
            case 'c':
                cout << "this is c\n";
                break;
            case 'p':
                cout << "this is p\n";
                break;
            case 't':
                cout << "this is t\n";
                break;
            case 'g':
                cout << "this is g\n";
                break;
            default:
                cout << "Please enter a c, p, t, or g:\n";
                continue;
        }
        showmenu();
    }
    return 0;
}

void showmenu() {
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore               p) pianist" << endl;
    cout << "t) tree                    g) game" << endl;
}