#include <iostream>
#include <cstring>
int main() {
    using namespace std;
    char first_name[20];
    char last_name[20];
    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "Here's the information in a single string: " << strcat(strcat(first_name, ", "),last_name) << endl;
    return 0;
}