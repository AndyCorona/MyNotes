#include <iostream>

int main() {
    using namespace std;
    char ch  = 'M';
    int i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;
    cout << "Displaying char ch using cout.put(ch): ";
    //使用 put 函数显示字符，和 << 相同
    cout.put(ch);
    cout.put('!');
    return 0;
}