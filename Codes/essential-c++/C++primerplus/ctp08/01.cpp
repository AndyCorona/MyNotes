#include <iostream>

using namespace std;

void print(const char *str, int n = 0);

int main() {
    const char *str = "hello";
    print(str);
    for (int i = 0; i < 5; i++) {
        print(str, 5);
    }
    return 0;
}

void print(const char *str, int n) {
    if (n == 0) {
        while (*str) {
            cout << *str;
            str++;
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << str[i];
        }
        cout << endl;
    }
}