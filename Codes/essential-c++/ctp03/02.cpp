#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> less_than_10(const vector<int> &vec);

int main() {
    int arr[20];
    for (int ix = 0; ix < 20; ++ix) {
        arr[ix] = ix;
    }
    vector<int> vec(arr, arr + 20);

    return 0;
}

/*
 * 返回一个新的 vector，内含小于 10 的所有元素
 */
vector<int> less_than_10(const vector<int> &vec) {
    vector<int> res_vec;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (vec[ix] < 10) {
            res_vec.push_back(vec[ix]);
        }
    }
    return res_vec;
}
