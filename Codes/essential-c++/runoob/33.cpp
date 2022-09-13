#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char data[100];

    ifstream inputfile;
    ofstream outputfile;
    //以读取文件模式打开文件
    inputfile.open("/Users/andycorona/Library/Containers/0AFCBEAE-938E-4F76-8EEB-133760E2F079/Data/Documents/data/CLion/essential-c++/runoob/input.txt", ios::in);
    //以写入文件模式打开文件
    outputfile.open("/Users/andycorona/Library/Containers/0AFCBEAE-938E-4F76-8EEB-133760E2F079/Data/Documents/data/CLion/essential-c++/runoob/output.txt",ios::out);
    if(!inputfile.is_open()) {
        cerr << "can not open the input file";
        return -1;
    }
    if (!outputfile.is_open()) {
        cerr  << "can not open the output file" << endl;
        return -1;
    }

    cout << "read from file" << endl;
    //一直读取到文件末尾
    while (!inputfile.eof()) {
        //从文件中读取
        inputfile >> data;

        //将数据写出到文件中
        outputfile << data;
    }
    cout << "write file" << endl;
    //手动关闭输入输出流
    inputfile.close();
    outputfile.close();
    return 0;
}