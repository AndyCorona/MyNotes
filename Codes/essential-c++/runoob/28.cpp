#include <iostream>

using namespace std;

class Line {
private:
    int length;
public:
    //声明静态成员变量
    static int objectCount;
    Line(int length = 10) {
        cout << "构造器被调用" << endl;
        this->length = length;
        objectCount++;
    }
    //静态成员函数
    static  int getCount() {
        return objectCount;
    }
};

//初始化静态成员变量
int Line::objectCount = 0;

int main() {
    Line line1(20);
    Line Line2(30);
    //使用静态成员函数
    cout << "对象被调用次数：" << Line::getCount() << endl;
    return 0;
}