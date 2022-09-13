#include <iostream>

using namespace std;

class Line {
private:
    double length;
public:
    friend void printLength(Line line);

    friend class BigLine;

    void setLength(double len);
};

void Line::setLength(double len) {
    this->length = len;
}

void printLength(Line line) {
    cout << "length of line" << line.length << endl;
}

//友元类的使用
class BigLine {
public:
    //BigLine 是  Line 的友元类，可以直接访问 Line 的任何成员
    void Print(int length, Line &line) {
        line.setLength(length);
        cout << "length of line" << line.length << endl;
    }
};


int main() {
    Line line;
    BigLine bigLine;
    line.setLength(10.0);
    printLength(line);
    bigLine.Print(20, line);
    return 0;
}