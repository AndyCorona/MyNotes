#include <iostream>

using namespace std;

class Line {
private:
    double length;

public:
    double getLength(void);
    void setLength(double len);
};

double Line::getLength() {
    return length;
}

void Line::setLength(double len) {
    this->length = len;
}

int main() {
    Line line;
    //报错，因为 length 是私有的
    //line.length = 10;
    line.setLength(10.0);
    cout << "length of line: " << line.getLength() << endl;
    return 0;
}
