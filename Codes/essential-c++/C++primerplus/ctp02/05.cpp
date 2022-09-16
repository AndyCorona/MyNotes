#include <iostream>

using namespace std;

int main() {
    int degree;
    cout << "Please enter a Celsius value: ";
    cin >> degree;
    cout << degree << " degrees Celsius is " << (degree * 1.8 + 32.0) << " degrees Fahrenheit." << endl;
    return 0;
}