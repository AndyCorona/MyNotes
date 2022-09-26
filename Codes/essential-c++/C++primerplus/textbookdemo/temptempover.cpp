#include <iostream>

struct debts {
    char name[50];
    double amount;
};

//数组中传递要娴熟的数据
template<typename T>
void ShowArray(T arr[], int n);

//数组中传递要显示的数据的指针
template<typename T>
void ShowArray(T *arr[], int n);

int main() {
    using namespace std;
    int things[6] = {13, 31, 104, 301, 310, 130};

    struct debts mr_E[3] = {
            {"A", 2400.0},
            {"B", 1300.0},
            {"C", 1800.0}
    };

    double *pd[3];
    for (int i = 0; i < 3; i++) {
        pd[i] = &mr_E[i].amount;
    }
    cout << "Listing counts of things:\n";
    ShowArray(things, 6);
    cout << "Listing debts:\n";
    ShowArray(pd, 3);
    return 0;
}

template<typename T>
void ShowArray(T arr[], int n) {
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template<typename T>
void ShowArray(T *arr[], int n) {
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++) {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}