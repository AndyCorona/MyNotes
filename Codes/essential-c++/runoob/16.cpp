#include <iostream>

using namespace std;


//定义结构体类型为 Books 的变量 boo
struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} boo;

//定义结构体类型为 Book，其别名为 book
typedef struct Book{
    int book_id;
    char title[50];
} book;


int main() {
    Books book1;
    Book book2;
    book book3;
    return 0;
}
