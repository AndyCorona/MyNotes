#include <iostream>

using namespace std;

void printTime(int hour, int minute) {
    cout << "Time: " << hour << ":" << minute << endl;
}

int main() {
    int hour, minute;
    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minute;
    printTime(hour, minute);
    return 0;
}