#include <iostream>
#include <string>
using namespace std;


int main() {
    string user_name;
    cout << "Please enter your name:";
    cin >> user_name;
    switch(user_name.size()) {
        case 0 :
            cout << "There is no name";
            break;
        case 1 :
            cout << "There is only one character";
            break;
        default:
            cout << "hello, " << user_name;
            break;
    }
    return 0;
}