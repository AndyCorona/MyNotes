#include <iostream>

using namespace  std;


class Line {
public:
    int getLength(void);
    Line(int len);
    ~Line(void);
    Line(const Line &obj);
private:
    int * ptr;
};

//定义拷贝构造函数
Line::Line(const Line &obj) {
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    //分配内存
    ptr = new int;
    //将 obj 中 ptr 指针保存的值赋给 ptr
    * ptr = *obj.ptr;
}

Line::Line(int len) {
    cout << "为指针分配动态内存" << endl;
    ptr = new int();
    *ptr = len;
}

Line::~Line() {
    cout << "回收分配的内存空间" << endl;
    delete ptr;
}

int Line::getLength() {
    return *ptr;
}

void display(Line obj) {
    cout << "line 大小" << obj.getLength() << endl;
}

int main() {
    Line line(10);
    //使用拷贝构造函数
    Line line_copy = line;
    display(line);
    display(line_copy);
    return 0;
}