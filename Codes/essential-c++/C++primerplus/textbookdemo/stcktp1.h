#ifndef STCKTP1_H
#define STCKTP1_H

template<typename Type>
class Stack {
private:
    enum {
        SIZE = 10
    };
    int stacksize;
    Type *items;
    int top;
public:
    explicit Stack(int ss = SIZE);

    Stack(const Stack &sk);

    ~Stack() {
        delete[] items;
    }

    bool isEmpty() {
        return top == 0;
    }

    bool isFull() {
        return top == stacksize;
    }

    bool push(const Type &item);

    bool pop(Type &item);

    Stack &operator=(const Stack &sk);
};

template<typename Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0) {
    items = new Type[stacksize];
}

template<class Type>
Stack<Type>::Stack(const Stack &stack) {
    stacksize = stack.stacksize;
    top = stack.top;
    items = new Type(stack.stacksize);
    for (int i = 0; i < top; i++) {
        items[i] = stack.items[i];
    }
}

template<typename Type>
bool Stack<Type>::push(const Type &item) {
    if (top < stacksize) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }

}

template<typename Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}

template<typename Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &st) {
    if (this == &st) {
        return *this;
    }
    delete[] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for (int i = 0; i < top; i++) {
        items[i] = st.items[i];
    }
    return *this;
}

#endif //STCKTP1_H
