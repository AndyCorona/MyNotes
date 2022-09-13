#include <iostream>

using namespace std;

void swap_by_value(int, int);
void swap_by_pointer(int &, int &);
void swap_by_reference(int *, int *);
//非法，默认值右侧的参数必须都有默认值
//void func(int = 10, int);
//合法
void func1(int = 10, int = 20);


int main() {
    int num1 = 10, num2 = 20;
    cout << "num1 is " << num1 << ", num2 is " << num2 << endl;
    swap_by_value(num1, num2);
    cout << "num1 is " << num1 << ", num2 is " << num2 << endl;

    int num3 = 10, num4 = 20;
    cout << "num3 is " << num3 << ", num4 is " << num4 << endl;
    swap_by_pointer(num3, num4);
    cout << "num3 is " << num3 << ", num4 is " << num4 << endl;

    int num5 = 10, num6 = 20;
    cout << "num5 is " << num5 << ", num6 is " << num6 << endl;
    swap_by_reference(&num5, &num6);
    cout << "num5 is " << num5 << ", num6 is " << num6 << endl;

    return 0;
}


/*
 * 传值调用，函数内对形参的修改不会影响实参
 */
void swap_by_value(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

/*
 * 指针调用
 */
void swap_by_pointer(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = num1;
}

/*
 * 引用调用
 */
void swap_by_reference(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}