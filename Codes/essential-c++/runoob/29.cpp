#include <iostream>

using namespace std;

class SubClass {
protected:
    int length;
public:
    void setLength(int len) {
        this->length = len;
    }
};

class SupClass : public SubClass {
public:
    int getLength() {
        //在子类中可以访问到父类中的成员
        return this->length;
    }
};


int main() {
    SupClass supClass;
    supClass.setLength(20);
    //继承了父类中的成员函数，可以直接使用
    cout << "length of supClass: " << supClass.getLength() << endl;
    return 0;
}