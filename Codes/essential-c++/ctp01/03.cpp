#include <iostream>
#include <vector>
#include <array>

using namespace std;
//用 vector 存储数据，vector 可以动态扩容
//int main() {
//    vector<int> ivector;
//    int value;
//    while(cin >> value) {
//        ivector.push_back(value);
//    }
//    int sum = 0;
//    for( int i = 0; i < ivector.size(); i++) {
//        sum += ivector[i];
//    }
//    cout << "total sum of vector is " << sum;
//    return 0;
//}

//用 array  存储数据
int main() {
    //数组需要定义初始容量
    const int capacity = 128;
    int index = 0;
    int temp = 0;
    int arr[index];
    while (cin >> temp && index < capacity) {
        arr[index++] = temp;
        cout << temp;
    }
    int sum = 0;
    //数组中存在未初始化的脏数据
    for (int i = 0; i < index; i++) {
        sum += arr[i];
        cout << arr[i];
    }
    cout << "total sum is " << sum;
    return 0;
}
