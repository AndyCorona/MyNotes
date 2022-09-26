#ifndef STACK_H
#define STACK_H


class customer {
    char fullname[50];
    double paymeny;
public:
    customer() {}

    customer(const char *fullname, double payment) {
        strncpy(this->fullname, fullname, 50);
        this->paymeny = payment;
    }

    const double get_payment(void) const {
        return this->paymeny;
    }
};


typedef customer Item;

class Stack {
private:
    enum {
        MAX = 10
    };
    Item items[MAX];
    int top;
public:
    Stack();

    bool isEmpty();

    bool isFull();

    bool push(const Item &item);

    bool pop(Item &item);
};

#endif //STACK_H
