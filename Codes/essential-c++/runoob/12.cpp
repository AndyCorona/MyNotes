#include <iostream>

using namespace std;

int main() {
    int num = 10;
    int *ptr = &num;
    int **second_ptr = &ptr;
    cout << "变量的值为：" << num << endl;
    cout << "变量的值为：" << *ptr << endl;
    cout << "变量的值为：" << **second_ptr << endl;
    return 0;
}