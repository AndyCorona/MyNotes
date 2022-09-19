#include <iostream>
struct CandyBar {
    char brand[20];
    double weight;
    int cla;
};
int main() {
    using namespace std;
    CandyBar *arr = new CandyBar[3];
    arr[0] = {
            "Mocha Munch",
            2.3,
            350
    };
    cout << "brand: " << arr[0].brand << endl;
    cout << "weight: " << arr -> weight << endl;
    cout << "cla: " << (*arr).cla << endl;
    return 0;
}