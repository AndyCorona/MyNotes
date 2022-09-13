#include <iostream>

using namespace  std;

class Line{
private:
    double length;
public:
    //友元函数的声明，但友元函数不是任何类的成员函数
    friend void printLength(Line line);
    void setLength(double len);
};

void Line::setLength(double len) {
    this->length = len;
};

//友元函数定义
void printLength(Line line) {
    //友元函数是 Line 的友元，所以可以直接访问该类的任何成员
    cout << "length of line: " << line.length << endl;
}

int main() {
    Line line;
    line.setLength(10.0);
    //使用友元函数
    printLength(line);
    return 0;
}