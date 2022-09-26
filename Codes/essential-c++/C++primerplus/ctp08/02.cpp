#include <iostream>

using namespace std;

struct CandyBar {
    char *brand;
    double weight;
    int cal;
};

void func(CandyBar &, char *dtr = "Millennium Munch", double weight = 2.85, int cal = 350);

void show(const CandyBar &);

int main() {
    using namespace std;
    CandyBar candybar;
    func(candybar, "hello", 2.39, 10);
    show(candybar);
    return 0;
}

void show(const CandyBar &candybar) {
    cout << candybar.brand << "\n";
    cout << candybar.weight << endl;
    cout << candybar.cal << endl;
}

void func(CandyBar &candybar, char *str, double weight, int cal) {
    candybar.brand = str;
    candybar.weight = weight;
    candybar.cal = cal;
}