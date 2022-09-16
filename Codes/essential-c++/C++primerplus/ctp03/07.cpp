#include <iostream>

using namespace std;

int main() {
    cout << "请输入百公里油耗（升/100公里）：";
    double mpg;
    cin >> mpg;
    cout << "每加仑行驶 " << 62.14 * 3.785 / mpg << " 英里" << endl;
    return 0;
}