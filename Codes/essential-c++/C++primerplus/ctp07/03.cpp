#include <iostream>

using namespace std;
struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show(box);

void setVolume(box *);

int main() {
    box b = {
            "box",
            1,
            2,
            3,
            0
    };
    show(b);
    setVolume(&b);
    show(b);
    return 0;
}

void show(box b) {
    cout << b.maker;
    cout << b.height;
    cout << b.width;
    cout << b.length;
    cout << b.volume;
}

void setVolume(box *b) {
    b->volume = b->height * b->width * b->length;
}
