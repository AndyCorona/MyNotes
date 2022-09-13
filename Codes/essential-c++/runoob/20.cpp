#include <iostream>

using namespace std;
class Line {
protected:
    double length;
};

class SmallLine:Line {
public:
    void setLength(double len);
    double getLength(void );
};

void SmallLine::setLength(double len) {
    //子类可以访问父类中 protected 变量
}
double SmallLine::getLength() {
    return this->length;
}

int main() {
    SmallLine smallLine;
    smallLine.setLength(10.0);
    cout << "length of smallline: " << smallLine.getLength() << endl;
    return 0;
}