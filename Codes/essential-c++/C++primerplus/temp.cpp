#include <iostream>

using namespace std;

class Line {
private:
    double length;
public:

    Line(const double length) {
        this->length = length;
    }

    //通过成员函数
    double convert_to_int() {
        return int(this->length);
    }

    //通过转换函数
    operator int() {
        return int(this->length);
    }
};

int main() {
    Line line{10.0};
    //显式调用成员函数
    int temp1 = line.convert_to_int();

    //编译器隐式调用转换函数
    int temp2 = int(line);
    int temp3 = (int) line;
    int temp = line;
    return 0;
}