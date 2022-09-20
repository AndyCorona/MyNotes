#include <iostream>

const int Seasons = 4;
//数组代替 array
const char *Snames[] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double *);

void show(const double *);

int main() {
    double expenses[Seasons] = {};
    fill(expenses);
    show(expenses);
    return 0;
}

void fill(double *arr) {
    using namespace std;
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*arr);
        arr++;
    }
}

void show(const double * da) {
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expense: $" << total << endl;
}