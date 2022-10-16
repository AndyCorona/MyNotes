#include <iostream>
#include <string>
#include <cctype>
#include "stacktp1.h"

using std::cin;
using std::cout;


int main() {
    Stack<std::string> st;
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order.\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && std::toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if (!std::isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number t odd: ";
                cin >> po;
                if (st.isFull()) {
                    cout << "stack is full\n";
                } else {
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if (st.isEmpty()) {
                    cout << "stack is empty\n";
                } else {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                    break;
                }
        }
        cout << "Please enter A  to add a purchase order, \n"
             << "P to process a PO, or Q to quit\n";
    }
    cout << "Byte\n";
    return 0;
}