#include <iostream>
using namespace  std;

class Line {
public:
    Line(int length = 10){
        cout << "构造器被调用" << endl;
        this->length = length;
    }
    int compare(Line line) {
        return this->length >= line.length;
    }
private:
    int length;
};

int main() {
    Line line1(10);
    Line line2(10);
    if (line1.compare(line2)) {
        cout << "line1 >= line2" << endl;
    } else {
        cout << "line1 < line2" << endl;
    }
    return 0;
}