#ifndef STACKTP1_H
#define STACKTP1_H

//模版类头文件
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

//模版类具体实现
template<class Type>
Stack<Type>::Stack() {
    top = 0;
}

template<class Type>
bool Stack<Type>::isEmpty() {
    return top == 0;
}

template<class Type>
bool Stack<Type>::isFull() {
    return top == MAX;
}


template<class Type>
bool Stack<Type>::push(const Type &item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

template<class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}


#endif //STACKTP1_H
