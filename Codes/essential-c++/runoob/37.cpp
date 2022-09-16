#include <iostream>

using namespace  std;

//定义命名空间
namespace first_space {
    void func() {
        cout << "in first space" << endl;
    }
}
namespace second_space{
    void func() {
        cout << "in second space" << endl;
    }
}

int main() {
    first_space::func();
    second_space::func();
    return 0;
}