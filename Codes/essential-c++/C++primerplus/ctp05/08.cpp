#include <iostream>
#include <cstring>

int main() {
    using namespace std;
    char word[20];
    cout << "Enter words (to stop, type the word done):\n";
    cin >> word;
    int count = 0;
    while (strcmp(word, "done")) {
        cin >> word;
        count++;
    }
    cout << "You enter a total of " << count << " words";

    return 0;
}