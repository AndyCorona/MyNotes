#include <iostream>

using namespace std;

int main() {
    int *ptr;
    cout << ptr << endl;
    cout << *ptr << endl;
    ptr = NULL;
    if (!ptr) {
        cout << "空指针" << endl;
    }
    cout << ptr << endl;
    cout << *ptr << endl;
    return 0;
}
