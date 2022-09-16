#include <iostream>

using namespace std;
#define PI 3.14159
#define MIN(a, b) (a < b ? a : b)
#define HEL(x) #x

int main() {
    cout << "Value of PI :" << PI << endl;
    cout << "较小的值为；" << MIN(10, 20) << endl;
    cout << HEL(hello) << endl;
    return 0;
}