#include <iostream>
#include <cmath>

struct polar {
    double distance;
    double angle;
};

struct rect {
    double x;
    double y;
};

void rect_to_polar(const rect *pxy, polar *pad);

void show_polar(const polar *pad);

int main() {
    using namespace std;
    rect rpalce;
    polar pplace;
    cout << "Enter the x and y values:";
    while (cin >> rpalce.x >> rpalce.y) {
        rect_to_polar(&rpalce, &pplace);
        show_polar(&pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

void rect_to_polar(const rect *pxy, polar *pad) {
    using namespace std;
    pad->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pad->angle = atan2(pxy->y, pxy->x);

}

void show_polar(const polar *pad) {
    using namespace std;
    const double Rad_to_deg = 57.295777951;
    cout << "distance = " << pad->distance;
    cout << ", angle = " << pad->angle * Rad_to_deg;
    cout << " degrees\n";
}