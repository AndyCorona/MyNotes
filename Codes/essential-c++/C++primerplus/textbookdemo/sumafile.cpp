#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 60;

int main() {
    using namespace std;
    char filename[SIZE];
    ifstream inFile;
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    //尝试打开文件
    inFile.open(filename);
    //如果文件没有打开
    if (!inFile.is_open()) {
        cout << "Could not open the file" << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;
    inFile >> value;
    //判断最后一次读取输入操作是否成功
    while (inFile.good()) {
        ++count;
        sum += value;
        inFile >> value;
    }
    if (inFile.eof()) {
        cout << "End of file reached.\n";
    } else if (inFile.fail()) {
        cout << "Input terminated by data mismatch.\n";
    } else {
        cout << "Input terminated for unknown reason.\n";
    }
    if (count == 0) {
        cout << "No data processed.\n";
    } else {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    //关闭输入流
    inFile.close();
    return 0;
}