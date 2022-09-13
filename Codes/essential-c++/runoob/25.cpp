#include <iostream>

using namespace std;

inline int Max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    cout << "Max(20,10): " << Max(10,20) << endl;
    cout << "Max(0,200): " << Max(0,200) << endl;
    cout << "Max(100,1010): " << Max(100,1010) << endl;
    return 0;
}