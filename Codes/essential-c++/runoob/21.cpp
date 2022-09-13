#include <iostream>

using namespace std;

class Line {
public:
    //声明构造函数
    Line();

    //带参数的构造函数
    Line(string msg);
    Line(string msg, double len);

    //声明析构函数
    ~Line(void);

    double length;
};

//定义无参构造函数
Line::Line() {
    //对象初始化处理
    //TODO
    this->length = 10.0;
}
//定义有参构造器
Line::Line(string msg) {
    cout << msg << endl;
}
//使用初始化列表来初始化字段
Line::Line(string msg, double len) : length(len) {
    cout << msg << endl;
}

//定义析构函数
Line::~Line(void) {
    cout << "the object is being deleted" << endl;
}


int main() {
    //使用无参构造器
    Line line1;
    cout << line1.length << endl;

    //使用有参构造器
    Line line2("this is line2 object");

    return 0;
}