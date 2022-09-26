#include <iostream>

const int ArSize = 10;

char *left(const char *, int n = 1);

int main() {
    using namespace std;
    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);
    char *ps = left(sample, 4);
    cout << ps << endl;
    delete[] ps;
    ps = left(sample);
    cout << ps << endl;
    delete[] ps;
    return 0;
}

char *left(const char *str, int n) {
    if (n < 0) {
        n = 0;
    }
    //创建临时字符串
    char *p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++) {
        p[i] = str[i];
    }
    //字符串过短，需要提前加上结束标志符
    while (i <= n) {
        p[i++] = '\0';
    }
    return p;
}