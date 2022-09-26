#include <iostream>


class Betelgeusean {
private:
    const static int LIMIT = 20;
    char name[LIMIT];
    int CI;
public:
    Betelgeusean(const char *name = "Plorga", int n = 50) {
        strncpy(this->name, name, LIMIT);
        this->CI = n;
    }

    void set_CI(const int n) {
        this->CI = n;
    }

    void show(void) const {
        std::cout << "name: " << this->name << ", ";
        std::cout << "CI: " << this->CI << std::endl;
    }
};

int main() {
    using namespace std;
    Betelgeusean plog1 = {"hello", 20};
    Betelgeusean plog2 = {};
    plog2.show();
    plog1.show();

    plog1.set_CI(1000);
    plog1.show();
    return 0;
}