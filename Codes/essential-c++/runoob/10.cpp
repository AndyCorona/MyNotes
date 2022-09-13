
#include <iostream>

using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr;
    for (int ix = 0; ix < 2; ix++) {
        cout << "指针所指向变量的值为" << ptr << endl;
        cout << "指针所指向变量的值为" << *ptr << endl;
        ptr++;
    }


    int *start_ptr = arr;
    while (start_ptr <= &arr[2]) {
        cout << "指针所指向内存地址为：" << start_ptr << endl;
        cout << "指针所指向变量的值为：" << *start_ptr << endl;
        start_ptr++;
    }

    cout << "数组首元素" << *arr << endl;
    cout << "数组首元素的内存地址" << arr << endl;
    //不合法，常量不能被更改
    *arr++;
    //合法
    *(arr + 3);
    return 0;
}