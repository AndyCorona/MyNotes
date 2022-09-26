#include <iostream>

struct job {
    char name[40];
    double salary;
    int floor;
};


//原始模版
template<typename T>
void Swap(T &a, T &b);

//显式具体化模版
template<>
void Swap<job>(job &j1, job &j2);

void Show(job &j);


int main() {
    using namespace std;
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = {"Susan", 73000.60, 7};
    job sidney = {"Taffee", 78060.72, 9};
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);
    cout << "After job swapping:\n";
    Show(sue);
    Show(sidney);
    return 0;
}

//原始模版
template<typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

//具体化的模版
template<>
void Swap<job>(job &j1, job &j2) {
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j) {
    using namespace std;
    cout << j.name << ": $" << j.salary
         << " on floor" << j.floor << endl;
}