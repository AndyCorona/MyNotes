#include <iostream>

int main() {
    using namespace std;
    int row;
    cout << "Enter number of rows: ";
    cin >> row;
    for (int i = 0; i < row; i++) {
        for (int k = row - 1; k > i; k--) {
            cout << ".";
        }
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}