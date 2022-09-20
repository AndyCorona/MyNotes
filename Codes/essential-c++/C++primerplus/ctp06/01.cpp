#include <iostream>
#include <cctype>

int main() {
    using namespace std;
    cout << "请输入（按@退出）：\n";
    char ch;
    cin >> ch;
    while (ch != '@') {
        if (islower(ch)) {
            cout << (char) toupper(ch) << endl;
        } else if (isupper(ch)) {
            cout << (char) tolower(ch) << endl;
        }
        cout << "请输入（按@退出）：\n";
        cin >> ch;
    }
    return 0;
}