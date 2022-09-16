#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    string address;
    cout << "Please enter your name:";
    cin >> name;
    cout << "Please enter your address:";
    cin >> address;
    cout << "Your name is " << name << ", your address is " << address << endl;
    return 0;
}