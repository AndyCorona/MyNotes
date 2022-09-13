#include <iostream>

using namespace std;

class printData {
public:
    //函数重载
    void print(int num) {
        cout << "整数为：" << num << endl;
    }

    void print(string input) {
        cout << "字符串为：" << input << endl;
    }

    void print(double f) {
        cout << "浮点数为：" << f << endl;
    }
};


int main() {
    printData pd;

    pd.print(10);
    pd.print("你好");
    pd.print(10.2);
    return 0;
}