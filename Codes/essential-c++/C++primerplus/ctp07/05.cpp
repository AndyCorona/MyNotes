#include <iostream>

long recurse(int);

int main() {
    using namespace std;
    cout <<"请输入一个数字：" << endl;
    int num;
    cin >> num;
    cout << num << "! = " << recurse(num) << endl;
    return 0;
}

long recurse(int n) {
    if (n <= 0) {
        return 1;
    }
    return recurse(n - 1) * n;
}
