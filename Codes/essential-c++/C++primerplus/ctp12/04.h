#ifndef ESSENTIAL_C___04_H
#define ESSENTIAL_C___04_H

typedef unsigned  long Item;

class Stack {
private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool  isEmpty();
    bool isFull();
    bool push(const Item & item);
    bool  pop(Item & item);
    Stack & operator=(const Stack & st);
};
#endif //ESSENTIAL_C___04_H
