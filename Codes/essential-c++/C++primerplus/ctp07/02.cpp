#include <iostream>

const int LEN = 10;
using namespace std;

int input(double []);

void show(const double[], int);

double avg(const double[], int);

int main() {
    double ar[LEN];
    int count = input(ar);
    show(ar, count);
    cout << "平均值为：" << avg(ar, count) << endl;
    return 0;
}

int input(double ar[]) {
    cout << "请输入成绩：\n";
    int i = 0;
    while (cin >> ar[i] && i < LEN) {
        i++;
        cout << "请输入成绩：\n";
    }
    return i - 1;
}

void show(const double ar[], int n) {
    for (int i = 0; i < n; i++) {
        cout << ar[i] << endl;
    }
}

double avg(const double ar[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[i];
    }
    return sum / n;
}