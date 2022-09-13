#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(vector<int>);

void bubble_sort(vector<int> &);

int main() {
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);
    cout << "vector before sorted: \n";
    display(vec);
    bubble_sort(vec);
    cout << "vector after sorted: \n";
    display(vec);
    return 0;
}

/*
 * 冒泡排序
 */
void bubble_sort(vector<int> &vec) {
    int len = vec.size();
    for (int ix = 0; ix < len - 1; ++ix) {
        for (int iy = ix + 1; iy < len; ++iy) {
            if (vec[iy] < vec[ix]) {
                int temp = vec[iy];
                vec[iy] = vec[ix];
                vec[ix] = temp;
            }
        }
    }
}

void display(vector<int> vec) {
    int len = vec.size();
    for (int ix = 0; ix < len; ++ix) {
        cout << vec[ix] << " ";
    }
    cout << endl;
}