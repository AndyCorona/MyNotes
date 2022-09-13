#include <iostream>
#include <vector>

using namespace std;

int *find(vector<int>, int);

int main() {
    int arr[8] = {1, 2, 3, 4, 5};
    vector<int> vec(arr, arr + 8);
    int *res = 0;
    int value = 4;
    res = find(vec, value);
    if (res == 0) {
        cout << value << " is not exist" << endl;
    } else {
        cout << value << " is exist!" << endl;
    }
    return 0;
}

/*
 *
 * 寻找数字在 vector 中是否存在，如果存在则返回该数组，否则返回 0
 */
int *find(vector<int> &vec, int value) {
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (vec[ix] == value) {
            return &vec[ix];
        }
    }
    return 0;
}

template<typename elemType>
elemType *find(const vector<elemType> &vec, int size, const elemType &value) {
    if (!vec || vec.size() == 0) {
        return 0;
    }
}

template<typename elemType>
elemType *find(const vector<elemType> &vec, const elemType &value) {
    if (!vec || vec.size() < 1) {
        return 0;
    }

    iterator<vec, string> itr;
    for (itr = begin(vec); itr != end(vec); itr++) {

    }
}

template<typename IteratorType, typename elemType>
IteratorType find(IteratorType first,IteratorType last, const elemType & value) {
    if (first == last) {
        return 0;
    }

    for (; )
}




