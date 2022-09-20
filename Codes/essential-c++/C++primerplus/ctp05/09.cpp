#include <iostream>
#include <string>

int main() {
    using namespace std;
    string word;
    cout << "Enter words (to stop, type the word done):\n";
    cin >> word;
    int count = 0;
    while (word != "done") {
        cin >> word;
        count++;
    }
    cout << "You enter a total of " << count << " words";

    return 0;
}