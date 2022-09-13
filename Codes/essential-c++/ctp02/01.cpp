#include <iostream>
#include <string>

using namespace std;

//函数原型
bool fibbon_elem(int, unsigned int &);
bool print_sequence(int);
//默认参数，1. 要么在函数定义要么在函数声明中指定一次；2. 函数默认值从右边开始解析
int defaultParam(int = 0);

/**
 * 用户输入 -1 退出程序，否则不断执行用户输入的数字的 Fibbonacci 函数
 * @return
 */
int main() {
    int pos;
    cout << "Please enter a number(enter -1 to exit): \n";
    //不断获取用户输入
    while (cin >> pos) {
        //如果输入 -1 则退出程序
        if (pos == -1) {
            break;
        }
        unsigned int elem;
        if (fibbon_elem(pos, elem)) {
            print_sequence(pos);
            cout << "element " << pos << " is " << elem << endl;
        } else {
            cout << "Sorry, can not calculate the " << pos << endl;
        }
    }
    cout << "no input, the default param is " << defaultParam() << endl;
    return 0;
}


bool fibbon_elem(int pos, unsigned int &elem) {
    //检查值是否在合理区间
    if (pos <= 0 || pos > 1024) {
        elem = 0;
        return false;
    }
    elem = 1;
    int n2 = 1, n1 = 1;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n1 + n2;
        n2 = n1;
        n1 = elem;
    }
    return true;
}

bool print_sequence(int pos) {
    if (pos <= 0 || pos > 1024) {
        cerr << "can not handler this number, number should be between 1 and 1023\n";
        return false;
    }
    cout << "The sequence number for " << pos << " is:\n\t";
    //所有位置都会打出 1 1，除了 pos == 1 除外
    switch (pos) {
        default:
        case 2:
            cout << "1 ";
        case 1 :
            cout << "1 ";
            break;
    }
    unsigned int elem;
    int n_1 = 1, n_2 = 1;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n_1 + n_2;
        n_2 = n_1;
        n_1 = elem;
        //一行打印 10 个元素
        cout << elem << ((!ix % 10) ? "\n\t" : " ");
    }
    cout << endl;
    return true;
}


int defaultParam(int num) {
    return num + 2;
}