#include <iostream>

const int LEN = 10;

int Fill_array(double *, int n);

void Show_array(double *, int);

void Reverse_array(double *, int);


int main() {
    double arr[LEN];
    int count = Fill_array(arr, LEN);
    Show_array(arr, count);
    Reverse_array(arr, count);
    Show_array(arr, count);
    Reverse_array(arr + 1, count - 2);
    Show_array(arr, count);
    return 0;
}


int Fill_array(double arr[], int n) {
    std::cout << "请输入 double 值：\n";
    double val;
    int i = 0;
    while (i < n && std::cin >> val) {
        arr[i++] = val;
        std::cout << "请输入 double 值：\n";
    }
    return i;
}

void Show_array(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void Reverse_array(double arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}