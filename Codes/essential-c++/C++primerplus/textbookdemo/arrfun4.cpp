#include <iostream>

const int ArSize = 8;

int sum_arr(const int *begin, const int *end);

int main() {
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    int sum = sum_arr(cookies, cookies + ArSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;
    sum = sum_arr(cookies, cookies + 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + 8);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";
    return 0;
}

//传入头尾指针
int sum_arr(const int *begin, const int *end) {
    const int *ptr;
    int total = 0;
    for (ptr = begin; ptr != end; ptr++) {
        total += *ptr;
    }
    return total;
}