#include <iostream>
#include "04.h"

Stack::Stack(int n) {
    size = n;
    top = 0;
    pitems = new Item[size];
}

Stack::Stack(const Stack &st) {
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++) {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack() {
    delete[] pitems;
};

bool Stack::isEmpty() {
    return top == 0;
}

bool Stack::isFull() {
    return top == size;
}

bool Stack::push(const Item &item) {
    if (top >= size) {
        std::cerr << "Stack is full\n";
        return false;
    }
    pitems[top++] = item;
    return true;
}

bool Stack::pop(Item &item) {
    if (top <= 0) {
        std::cerr << "Stack is empty\n";
        return false;
    }
    item = pitems[--top];
    return true;
}

Stack &Stack::operator=(const Stack &st) {
    if (this == &st) {
        return *this;
    }
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++) {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

#include <cctype>

int main() {
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order; \n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isFull()) {
                    cout << "stack already full\n";
                } else {
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if (st.isEmpty()) {
                    cout << "stack already empty.\n";
                } else {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
                break;
        }
        cout << "Please enter A to add a purchase order, \n"
             << "P to process a PO, or Q to quit.\n";
    }
    Stack st_new = st;
    while(!st_new.isEmpty()) {
        st_new.pop(po);
        cout << "PO #" << po << " popped\n";
    }
    Stack st2;
    st2 = st;
    while(!st2.isEmpty()) {
        st2.pop(po);
        cout << "PO #" << po << " popped\n";
    }
    cout << "Bye\n";
    return 0;
}

