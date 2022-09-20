#include <iostream>

const int MAX = 5;

double *fill_array(double *begin, int limit);

void show_array(const double *begin, double *end);

void revalue(double r, double *begin, double *end);

int main() {
    using namespace std;
    double properties[MAX];
    const double *begin = properties;
     double *end = fill_array(properties, MAX);
    show_array(begin, end);
    if (end != begin) {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; lease enter a number: ";

        }
        revalue(factor, properties, end);
        show_array(begin, end);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

//填充数组
double *fill_array(double *begin, int size) {
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
        begin[i] = temp;
    }
    //返回最后一个指针
    return begin + i;
}

//打印数组
void show_array(const double *begin, double *end) {
    using namespace std;
    int count = 0;
    for (const double *i = begin; i != end; i++) {
        cout << "Property #" << (count + 1) << ": $";
        cout << *i << endl;
        count++;
    }
}

//将数组中所有元素都进行变换
void revalue(double r, double *begin, double *end) {
    for (double *i = begin; i != end; i++) {
        *i *= r;
    }
}