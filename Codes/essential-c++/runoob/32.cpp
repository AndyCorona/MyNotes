#include <iostream>

using namespace std;

class Shape {
protected:
    int width;
    int heigth;
public:
    Shape(int wid = 0, int hei = 0) {
        this->width = wid;
        this->heigth = hei;
    }

    //静态多态，早绑定。area 函数在程序编译期间已经设置好
    int area() {
        cout << "调用父类方法" << endl;
        return 0;
    }
    //动态绑定
//    virtual int area() {
//        cout << "调用父类方法" << endl;
//        return 0;
//    }
};


class Rectangle : public Shape {
public:
    Rectangle(int a, int b) : Shape(a, b) {}

    int area() {
        cout << "调用子类1的方法" << endl;
        return width * heigth;
    }
};


class Triangle : public Shape {
public:
    Triangle(int a, int b) : Shape(a, b) {}

    int area() {
        cout << "调用子类2的方法" << endl;
        return width * heigth / 2;
    }
};


int main() {

    Shape *shape;
    Rectangle rectangle(10, 7);
    Triangle triangle(10, 7);
    shape = &rectangle;
    shape->area();
    shape = &triangle;
    shape->area();
    return 0;
}