

#include <iostream>

using namespace std;

int main() {
    //指针数组，保存两个 int 指针
    int *ptr_arr[2];
    int arr1[] = {1,2};
    int arr2[] = {3,4};
    ptr_arr[0] = &arr1[0];
    ptr_arr[0] = &arr2[0];
    return 0;
}