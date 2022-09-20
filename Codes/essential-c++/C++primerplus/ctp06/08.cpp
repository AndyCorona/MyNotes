#include <iostream>
#include <fstream>
#include <string>
int main() {
    using namespace std;
    //保存文件名
    string filename;
    cout << "请输入文件名：";
    cin >> filename;
    //创建文件流
    fstream inFile;
    inFile.open(filename,ios::in);
    if (!inFile.is_open()) {
        cout << "无法无法文件" << filename << endl;
        exit(EXIT_FAILURE);
    }
    //初始化文件个数
    int count = 0;
    char ch;
    inFile >> ch;
    while(inFile.good()) {
        ++count;
        inFile >> ch;
    }

    //到达文件末尾
    if (inFile.eof()) {
        cout << "到达文件末尾" << endl;
    }
    cout << "文件字符总数：" << count << endl;

    //关闭文件流
    inFile.close();
    return 0;
}