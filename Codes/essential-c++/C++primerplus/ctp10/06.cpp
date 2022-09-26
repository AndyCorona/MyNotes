#include <iostream>

class Move {
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0) {
        this->x = a;
        this->y = b;
    }

    void showMove() const {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }

    Move add(const Move &m) const {
        Move temp;
        temp.x = m.x + this->x;
        temp.y = m.y + this->y;
        return temp;
    }

    Move &reset(double a = 0, double b = 0) {
        this->x = a;
        this->y = b;
        return *this;
    }

};

int main() {
    Move move1{};
    Move move2{10, 20};
    move1.showMove();
    move2.showMove();
    Move move3 = {20, 10};
    move1 = move2.add(move3);
    move1.showMove();
    move1.reset();
    move1.showMove();
    return 0;
}
