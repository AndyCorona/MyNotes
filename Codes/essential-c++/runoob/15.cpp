#include <ctime>
#include <iostream>

using namespace std;


struct books {
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
} book;

int main() {
    // ????????????????/???
    time_t now = time(0);

    // ?? now ????????????
    char *dt = ctime(&now);

    cout << "????????????" << dt << endl;

    // ?? now ???? tm ??
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC ????????" << dt << endl;
}

