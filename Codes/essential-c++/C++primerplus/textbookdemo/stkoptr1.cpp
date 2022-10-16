
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "stcktp1.h"

const int NUM = 10;

int main() {
    std::srand(std::time(0));
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;
    Stack<const char *> st(stacksize);
    const char *in[NUM] = {
            "1:a", "2:b", "3:c", "4:d", "5:e", "6:f", "7:g", "8:h", "9:i", "10:j"
    };
    const char *out[NUM];
    int processed = 0;
    int nextin = 0;
    while (processed < NUM) {
        if (st.isEmpty()) {
            st.push(in[nextin++]);
        } else if (st.isFull()) {
            st.pop(out[processed++]);
        } else if (std::rand() % 2 && nextin < NUM) {
            st.push(in[nextin++]);
        } else {
            st.pop(out[processed++]);
        }
    }

    for (int i = 0; i < NUM; i++) {
        std::cout << out[i] << std::endl;
    }
    std::cout << "Bye.\n";
    return 0;
}