#include <iostream>
#include "05.h"

Stack::Stack() {
    top = 0;
}

bool Stack::isEmpty() {
    return top == 0;
}

bool Stack::isFull() {
    return top == MAX;
}

bool Stack::push(const Item &item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

bool Stack::pop(Item &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}

int main(void) {
    using namespace std;
    Stack stack;
    static int total;
    for (int i = 0; i < 10; i++) {
        customer cus = {"name_" + i, double(i)};
        stack.push(cus);
    }
    customer temp{};
    for (int i = 0; i < 10; i++) {
        stack.pop(temp);
        total += temp.get_payment();
    }
    cout << "total: " << total << endl;
    return 0;
}