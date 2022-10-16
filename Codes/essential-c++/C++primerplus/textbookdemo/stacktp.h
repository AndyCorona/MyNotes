#ifndef STACKTP_H
#define STACKTP_H

template<class Type>
class Stack {
private:
    enum {
        MAX = 10
    };

    Type items[MAX];
    int top;
public:

    Stack();

    bool isEmpty();

    bool isFull();

    bool push(const Type &item);

    bool pop(Type &tp);
};

template<typename Type>
Stack<Type>::Stack() { top = 0;}

template<typename Type>
bool Stack<Type>::isEmpty() {
    return top == 0;
}

template<typename Type>
bool Stack<Type>::isFull() {
    return top == MAX;
}

template<typename Type>
bool Stack<Type>::pop(Type &ty) {
    if (top > 0) {
        ty = items[--top];
    } else {
        return false;
    }
}

template<typename Type>
bool Stack<Type>::push(const Type &tp) {
    if (top > MAX) {
        return false;
    }
    items[top++] = tp;
    return true;
}


#endif //STACKTP_H
