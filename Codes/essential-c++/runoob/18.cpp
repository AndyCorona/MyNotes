#include <iostream>

using namespace  std;

class Line{
public:
    double length;
    void setLength(double len);
    double getLength(void);
};

//成员函数定义
double Line::getLength() {
    return length;
}

void Line::setLength(double len) {
    this->length = len;
}

int main() {
    Line line;
    //通过成员函数访问公有变量
    line.setLength(0);
    cout << "length of line: " << line.getLength() << endl;

    //直接访问公有变量
    line.length = 10.0;
    cout << "length of line: " << line.length << endl;
    return 0;
}

