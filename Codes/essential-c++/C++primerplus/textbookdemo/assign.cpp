#include <iostream>

int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    //int 转为 float
    float tree = 3;
    //double 转为 int
    int guess(3.9832);
    //double 转为 int
    int debt = 7.2E12;
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt =  " << debt << endl;
    return 0;
}