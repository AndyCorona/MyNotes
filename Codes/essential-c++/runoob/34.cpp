#include <iostream>

using namespace std;


int main() {
    try {
        int b = 0;
        if (b == 0) {
            //抛出异常
            throw "division by zero";
        }
    //捕获异常
    } catch (const char *msg) {
        cout << msg << endl;
    }
    return 0;
}