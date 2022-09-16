#include <iostream>

using namespace  std;
void fun1(void) {
    cout << "Three blind mice" <<endl;
}

void fun2(void) {
    cout << "See how they run" << endl;
}

int main() {
    for (int ix = 0; ix < 2; ix++) {
        fun1();
    }

    for (int ix = 0; ix < 2; ix++) {
        fun2();
    }
    return 0;
}