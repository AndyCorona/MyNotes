#include <iostream>

int main() {
    using namespace  std;
    cout <<"\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:_______\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";

    //显示中文
    wchar_t ni2 = L'\u4f60' ;
    //需要使用 wcout 输出
    wcout << ni2 << endl;

    char16_t ni3 = u'\u4f60';
    char32_t ni4 = U'\u4f60';
    cout.put(ni3) << endl;
    cout.put(ni4) << endl;
    return 0;
}