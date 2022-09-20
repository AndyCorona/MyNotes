#include <iostream>

const int Max = 5;

int main() {
    using namespace std;
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " Rounds.\n";
    int i;
    for (i = 0; i < Max; i++) {
        cout << "round #" << i + 1 << ": ";
        //如果输入不合法
        while (!(cin >> golf[i])) {
            //重置输入，否则 cin 不会读取接下来的输入
            cin.clear();
            //读取行尾之前的所有错误输入，等于删除错误输入
            while (cin.get() != '\n') {
                continue;
            }
            cout << "Please enter a number: ";
        }
    }
    double total = 0.0;
    for (i = 0; i < Max; i++) {
        total += golf[i];
    }
    cout << total / Max << " = average score "
         << Max << " Rounds\n";
    return 0;
}