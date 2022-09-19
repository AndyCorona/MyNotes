#include <iostream>
#include <string>
int main() {
    using namespace std;
    char char1[20];
    char char2[20] = "jagure";
    string str1;
    string str2 = "panther";
    cout << "Enter a king of feline: ";
    cin >> char1;
    cout << "Enter another kind of feline:\n";
    cin >> str1;
    cout << char1 << " " << char2 << " " << str1 << " " << str2 << endl;
    cout << "The third letter in " << char2 << " is " << char2[2] << endl;
    cout << "The third letter in " << str2 << " is " << str2[2] << endl;
    return 0;
}