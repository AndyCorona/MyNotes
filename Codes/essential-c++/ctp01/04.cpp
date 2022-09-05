#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    //获取文件输入流
    ifstream input("E:\\BaiduNetdiskDownload\\CLion\\essential-c++\\input.txt");
    if (!input) {
        cerr << "can not open this file\n";
        return -1;
    }
    //以追加方式输出文件
    ofstream output("E:\\BaiduNetdiskDownload\\CLion\\essential-c++\\output.txt", ios_base::app);
    if (!output) {
        cerr << "can not save data to the file: output.txt\n";
        return -2;
    }
    string word;
    vector<string> text;

    while (input >> word) {
        text.push_back(word);
    }
    //输入未排序字符
    cout << "unsorted string: \n";
    for (int i = 0; i < text.size(); i++) {
        cout << text[i] << ' ';
    }
    //添加换行符并刷新缓冲区
    cout << endl;
    //对数组进行排序
    sort(text.begin(), text.end());
    cout << "sorted string: \n";
    for (int i = 0; i < text.size(); i++) {
        output << text[i] << ' ';
    }
    output << endl;
    return 0;
}
