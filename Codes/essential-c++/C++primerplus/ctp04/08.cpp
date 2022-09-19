#include <iostream>

struct pizza {
    char name[20];
    int length;
    double weight;
};

int main() {
    using namespace std;
    cout << "Enter the name: ";
    pizza *pi = new pizza;
    cin >> pi -> name;
    cout << "Enter the length: ";
    cin >> pi -> length;
    cout << "Enter the weight: ";
    cin >> pi -> weight;
    cout << "name: " << pi->name << endl;
    cout << "length: " << pi->length << endl;
    cout << "weight: " << pi->weight << endl;
    delete pi;
    return 0;
}