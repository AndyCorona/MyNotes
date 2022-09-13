#include <iostream>
#include <exception>

using namespace  std;

//自定义异常
struct MyException : public exception {
    const char * what() throw() {
        return "My Exception";
    }
};

int main(){
    try{
        throw MyException();
    } catch (MyException &exception) {
        cout << exception.what() << endl;
    }
    return 0;
}