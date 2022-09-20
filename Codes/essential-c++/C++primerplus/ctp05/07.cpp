#include <iostream>

using namespace std;

struct car {
    char make[20];
    int year;
};

int main() {
    int count = 0;
    cout << "How many cars do you wish to catalog?\n";
    cin >> count;
    cin.get();
    car *cars = new car[2];
    for (int i = 0; i < count; i++) {
        cout << "Car #" << i + 1 << ":\n" ;
        cout << "Please enter the make: ";
        cin.getline(cars[i].make,20);
        cout << "Please enter the year made: ";
        cin >> cars[i].year;
        cin.get();
    }
    cout << "Here is your collection:" << endl;
    for (int i = 0; i < count; i++) {
        cout << cars[i].year << " " << cars[i].make << endl;
    }
    return 0;
}