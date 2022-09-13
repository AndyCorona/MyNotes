#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
public:
    bool push(const string &);

    bool pop(string &elem);

    bool peek(string &elem);

    bool empty();

    bool full();

    int size() { return _stack.size(); }

private:
    vector<string> _stack;
};

void fill_stack(Stack &stack, istream &is = cin) {
    string str;
    while (is >> str && stack.full()) {
        stack.push(str);
    }
    cout << "Read in " << stack.size() << " elements\n";
}

inline bool Stack::empty() {
    return _stack.empty();
}


int main() {
    return 0;
}

class Triangular {
public:
    int length() const { return _length; }

    int beg_pos() const { return beg_pos(); }

    int ele(int pos) const;

    bool next(int &val);

    void next_reset() { _next = _begin_pos - 1; }

private:
    int _length;
    int _begin_pos;
    int _next;
};
