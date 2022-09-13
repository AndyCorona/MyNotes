#include <iostream>

using namespace std;

class Line {
public:
    Line() {
        cout << "调用构造函数" << endl;
    }
    ~Line() {
        cout << "调用析构函数" << endl;
    }
private:
    int length;
};

//为变量动态分配内存
int main() {
    //初始化指针
    int * ptr = NULL;
    //为变量申请内存
    ptr = new int ;

    //释放内存
    delete ptr;

    Line line;
}