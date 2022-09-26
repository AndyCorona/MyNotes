#include <iostream>

namespace SALES {
    const int QUARTERS = 4;
    struct Sales {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    void setSales(Sales &s, const double ar[], int n) {
        n = n > QUARTERS ? QUARTERS : n;
        double min = ar[0];
        double max = ar[0];
        double total = 0.0;
        for (int i = 0; i < n; i++) {
            s.sales[i] = ar[i];
            total += ar[i];
            if (min > ar[i]) {
                min = ar[i];
            }
            if (max < ar[i]) {
                max = ar[i];
            }
        }
        s.min = min;
        s.max = max;
        s.average = total / n;
    }

    void setSales(Sales &s) {
        double total = 0.0;
        double min = 0.0;
        double max = 0.0;
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "请输入数字:" << std::endl;
            std::cin >> s.sales[i];
            total += s.sales[i];
            if (min > s.sales[i]) {
                min = s.sales[i];
            }
            if (max < s.sales[i]) {
                max = s.sales[i];
            }
        }
        s.min = min;
        s.max = max;
        s.average = total / QUARTERS;
    }

    void showSales(const Sales &s) {
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << s.sales[i] << " ";
        }
        std::cout << std::endl;
        std::cout << s.average << std::endl;
        std::cout << s.min << std::endl;
        std::cout << s.max << std::endl;
    }
}