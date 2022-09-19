#include <iostream>
#include <array>
int main() {
    using namespace std;
    array<int,3> record;
    cout << "Enter count1:";
    cin >> record[0];
    cout << "Enter count2:";
    cin >> record[1];
    cout << "Enter count3:";
    cin >> record[2];
    cout << "count: " << record.size() << endl;
    cout << "score(avg): " << (record[0] + record[1] + record[2]) / 3 << endl;
    return 0;
}