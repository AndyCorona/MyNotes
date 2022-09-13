#include <iostream>

using namespace std;

int main() {
    //PART I typedef 定义一个类型的别名，将 char * 定义为 CHAR
    typedef char *CHAR;
    char *str1 = "hello";
    CHAR str2 = "hell1o";
    //true
    cout << (str1 == str2);


    //PART II 定义结构体的别名
    //没有使用别名之前
    struct point {
        int x;
        int y;
    };
    struct point p1;

    //使用别名之后
    typedef struct ptr {
        int x;
        int y;
    } pot;
    pot p2;
    return 0;
}