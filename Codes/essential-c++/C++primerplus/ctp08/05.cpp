#include <iostream>

template<typename T>
T maxn(T arr[5]);

int main() {
    using namespace std;
    int arr[] = {1,2,3,4,5};
    double arr1[] = {1.2,3.4,3.1,6.4,2.1,0,9};
    cout << maxn(arr) << endl;
    cout << maxn(arr1) << endl;
    return 0;
}

template<typename T>
T maxn(T arr[5]) {
    T max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}