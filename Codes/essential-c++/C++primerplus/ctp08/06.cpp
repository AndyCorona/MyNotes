#include <iostream>

template<typename T>
T maxn(T arr[], int n);

template<>
char * maxn<char *>(char * arr[], int n);

int main() {
    using namespace std;
    int int_arr[] = {1, 2, 3, 5, -10, 100};
    double double_arr[] = {1.0, -0.99, 99, 0.5, 4.0};
    char *char_arr[] = {"hello", "andy", "abcdefg", "abcdefg", "d"};
    cout << maxn(int_arr, 6) << endl;
    cout << maxn(double_arr, 4) << endl;
    cout << maxn(char_arr, 5) << endl;
    return 0;
}

template<typename T>
T maxn(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

template<>
char * maxn<char *>(char * arr[], int n) {
    char * res = arr[0];
    int max = strlen(arr[0]);
    for (int i = 1; i < n; i++) {
        int now = strlen(arr[i]);
        if (now > max) {
            res = arr[i];
        }
    }
    return res;
}
