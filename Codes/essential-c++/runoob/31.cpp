#include <iostream>

using namespace std;

class Line {
public:

    Line();

    Line(int len) {
        this->length = len;
    }

    //运算符重载，重载 + 号，把两个对象相加并返回新的对象
    Line operator+(const Line &l) {
        Line line;
        line.length = this->length + l.length;
        return line;
    }
    int length;
};


int main() {
    Line line1(10);
    Line line2(20);
    Line line3;
    cout << "length of line1: " << line1.length << endl;
    cout << "length of line2: " << line2.length << endl;
    //使用重载运算符
    line3 = line1 + line2;
    cout << "length of line3: " << line3.length << endl;
    return 0;
}