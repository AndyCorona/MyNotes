#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Please enter your first name and last name:";
    string first_name;
    string last_name;
    cin >> first_name;
    cin >> last_name;
    cout << '\n'
         << "Hello, "
         << first_name
         << last_name
         << " ... and goodbye!\n";
    return 0;
}
