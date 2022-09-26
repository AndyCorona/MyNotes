#include <iostream>
#include <new>

using namespace std;

const int BUF = 512;
const int N = 2;

struct chaff {
    char dross[20];
    int slag;
};

chaff buffer[BUF];

void setChaff(chaff &);

void showChaff(const chaff &);

int main() {
    chaff *pt1 = new chaff[N];
    chaff *pt2 = new(buffer) chaff[N];
    for (int i = 0; i < N; i++) {
        setChaff(pt1[i]);
        setChaff(pt2[i]);
    }
    for (int i = 0; i < N; i++) {
        showChaff(pt1[i]);
        showChaff(pt2[i]);
    }
    return 0;
}

void setChaff(chaff &cf) {
    cf.slag = 10;
    strcpy(cf.dross, "hello");
}

void showChaff(const chaff &cf) {
    cout << cf.slag;
    cout << cf.dross;
}
