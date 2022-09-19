#include <iostream>

int main() {
    using namespace std;
    string name;
    string dessert;

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favotire dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;
    return 0;
}