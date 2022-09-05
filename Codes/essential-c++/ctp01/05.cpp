#include <iostream>

using namespace std;

const char *msg_to_user(int num_tries) {
    const int res = 4;
    static const char *arr[res] = {
            "msg1",
            "mag2",
            "msg3",
            "msg4"
    };
    if (num_tries < 0) {
        num_tries = 0;
    }
    if (num_tries >= res) {
        num_tries = res - 1;
    }
    return arr[num_tries];
}