#include <iostream>

using namespace std;

//定义 Box 对象
class Box {
public:
    //成员函数声明
    double get(void);
    void set(double height, double width);
private:
    double height;
    double width;
};


class Box2 {
public:
    double height;
    double width;
    //内联函数
    double get(void) {
        return height * width;
    }
};

//在类外部定义成员函数
void Box::set(double height, double width) {
    this->height = height;
    this->width = width;
}
double Box::get() {
    return this->width * this->height;
}

int main() {
    //声明 Box 对象
    Box box1;
    return 0;
}
