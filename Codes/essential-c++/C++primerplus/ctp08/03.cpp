#include <iostream>
#include <cctype>

using namespace std;

void toupp(const char *str);

int main() {
    cout << "Enter a string (q to quit): ";
    char ch[40] = {};
    cin.getline(ch, 40);
    while (strcmp(ch,"q")) {
        toupp(ch);
        cout << "Next string (q to quit): ";
        cin.getline(ch,40);
    }
    cout << "Bye." << endl;
    return 0;
}


void toupp(const char *str) {
    while (*str) {
        cout << char(toupper(*str));
        str++;
    }
    cout << endl;
}