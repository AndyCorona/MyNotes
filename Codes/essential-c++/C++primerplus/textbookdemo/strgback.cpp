#include <iostream>

char *buildstr(char c, int n);

int main() {
    using namespace std;
    int times;
    char ch;
    cout << "Enter a characters: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;
    //构建字符串
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    //释放内存
    delete[] ps;
    //重用指针
    ps = buildstr('+', 20);
    cout << ps << "Done" << ps <<endl;
    delete[] ps;
    return 0;
}

char *buildstr(char c, int n) {
    char *ptr = new char[n + 1];
    //加上字符串末尾标志符
    ptr[n] = '\0';
    while (n-- > 0) {
        ptr[n] = c;
    }
    return ptr;
}