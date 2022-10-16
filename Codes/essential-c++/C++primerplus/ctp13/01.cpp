#include <iostream>

using namespace std;

#include "01.h"

void Bravo(const cd &disk);

int main() {
    cd c1{"Beatles", "Capitol", 14, 35.5};
    Classic c2 = Classic{"Piano Sonata in B flatm Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17};
    cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.report();
    c2.report();
    cout << "Using type cd * pointer to objects:\n";
    pcd->report();
    pcd = &c2;
    pcd->report();
    cout << "Calling a function with a cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.report();
    return 0;
}

void Bravo(const cd &disk) {
    disk.report();
}