#include <iostream>

using namespace std;

int main() {
    int degree, minute, second;
    cout << "Enter a latitudes, minutes, and seconds: " << endl;
    cout << "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of ard: ";
    cin >> second;
    cout << degree << " degree, " << minute << " minutes, " << second << " seconds = ";
    double result = degree + double(minute / 60.0) + double(second / 60.0 / 60.0);
    cout << result << " degrees";
    return 0;
}