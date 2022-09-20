#include <iostream>

const int MAX = 5;

int fill_array(double ar[], int limit);

void show_array(const double arr[], int n);

void revalue(double r, double ar[], int n);

int main() {
    using namespace std;
    double properties[MAX];

    int size = fill_array(properties, MAX);
    show_array(properties, size);
    if (size > 0) {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; lease enter a number: ";

        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

//填充数组
int fill_array(double arr[], int size) {
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < size; i++) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        //如果输入非浮点数
        if (!cin) {
            cin.clear();
            //将所有非浮点数从队列中移除
            while (cin.get() != '\n') {
                continue;
            }
            cout << "Bad input; input process terminated.\n";
            break;
        } else if (temp < 0) {
            break;
        }
        arr[i] = temp;
    }
    return i;
}

//打印数组
void show_array(const double arr[], int n) {
    using namespace std;
    for (int i = 0; i < n; i++) {
        cout << "Property #" << (i + 1) << ": $";
        cout << arr[i] << endl;
    }
}

//将数组中所有元素都进行变换
void revalue(double r, double ar[], int n) {
    for (int i = 0; i < n; i++) {
        ar[i] *= r;
    }
}