#include <iostream>

using namespace std;

int main() {
    const double factor1 = 2.0;
    const double factor2 = 3.0;
    double height;
    cout << "Enter your weight: ";
    cin >> height;
    cout << "Your height is " << height * factor1 << endl;
    cout << "Your height is " << height * factor2 << endl;
    return 0;
}