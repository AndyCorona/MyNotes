#include <iostream>
struct CandyBar {
    char brand[20];
    double weight;
    int cla;
};
int main() {
    using namespace std;
    CandyBar snack = {
            "Mocha Munch",
            2.3,
            350
    };
    cout << "brand: " << snack.brand << endl;
    cout << "weight: " << snack.weight << endl;
    cout << "cla: " << snack.cla << endl;
    return 0;
}