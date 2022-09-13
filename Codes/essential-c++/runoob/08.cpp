#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    char str1[10] = "hello";
    char str2[10] = "world";
    //将 str1 和 str2 连接
    cout << strcat(str1, str2) << endl;
    //计算字符串长度
    cout << strlen(str1) << endl;


    string string1 = "hello";
    string string2 = "world";
    //连接两个字符串
    cout << string1 + string2 << endl;
    //计算字符串长度
    cout << string1.size() << endl;
    return 0;
}