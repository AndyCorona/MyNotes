#include <iostream>

using namespace std;

double converter(double year);


double converter(double year) {
    return year * 63240;
}

int main() {
    double year;
    cout << "Enter the number of light year: " ;
    cin >> year;
    cout << year << " light years = " << converter(year) << " astronomical units." << endl;
    return 0;
}