#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> words;
    string tword;
    while (cin >> tword) {
        words[tword]++;
    }
    //遍历 map 集合
    map<string, int>::iterator it = words.begin();
    for (; it != words.end(); it++) {
        cout << "key" << it->first << "value" << it->second;
    }
    return 0;
}


