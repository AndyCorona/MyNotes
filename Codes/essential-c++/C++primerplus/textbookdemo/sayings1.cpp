#include <iostream>
#include "string1.h"

const int MaxLen = 80;
const int ArSize = 10;

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    String name;

    cout << "Hi, What's your name?\n";
    cin >> name;

    cout << name << ", Please enter up tp ";
    cout << ArSize << " short sayings <empty line to quit>:\n";


    String sayings[ArSize];
    char temp[MaxLen];

    int i;

    for (i = 0; i < ArSize; i++) {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        //丢弃过长的字符串
        while (cin && cin.get() != '\n') {
            continue;
        }

        if (!cin || temp[0] == '\0') {
            break;
        } else {
            sayings[i] = temp;
        }
    }
    int shortest = 0;
    int first = 0;
    int total = i;
    if (total > 0) {
        cout << "Here are your sayings:\n";
        for (int i = 0; i < total; i++) {
            if (sayings[i].length() < sayings[shortest].length()) {
                shortest = i;
            }
            if (sayings[i] < sayings[first]) {
                first = i;
            }
        }
        cout << "shortest sayings:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany << " String objects. Bye.\n" << endl;
    } else {
        cout << "No input! Bye.\n";
    }
    return 0;
}