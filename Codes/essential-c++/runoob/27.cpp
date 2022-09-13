#include <iostream>

using namespace std;
class Line {
public:
    Line(int length = 10) {
        this->length = length;
    }
    int length;
};

int main() {
    Line line(20);
    //声明指向类的指针
    Line * ptrLine;
    //保存对象的内存地址
    ptrLine = &line;
    //通过成员访问运算符访问成员
    cout << "length of line" << ptrLine->length << endl;
    return 0;
}