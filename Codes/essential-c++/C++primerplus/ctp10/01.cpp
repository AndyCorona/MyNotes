#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string name;
    string account;
    double balance;
public:
    Account() {
        this->name = "默认用户名";
        this->account = "0000000000";
        this->balance = 0.0;
    }

    ~Account() {}

    Account(const string &name, const string &account, double balance) {
        this->name = name;
        this->account = account;
        this->balance = balance;
    }

    void set_name(const string name) {
        this->name = name;
    };

    void set_account(const string account) {
        this->account = account;
    }

    void set_balance(const double balance) {
        this->balance = balance;
    }

    void show(void) const {
        cout << "姓名：" << this->name << ", ";
        cout << "账户：" << this->account << ", ";
        cout << "余额：" << this->balance << "\n";
    }

    const string &get_name() const {
        return this->name;
    }

    const string &get_account() const {
        return this->account;
    }

    const double get_balance() const {
        return this->balance;
    }
};


int main() {
    Account account = {"张三", "2222222222", 2000};
    Account account1;
    Account account2 = {"李四", "1111111111", 30000};

    account.show();
    account1.show();
    account2.show();

    account1.set_name("王武");
    account1.set_balance(99999999.0);
    account1.set_account("3333333333");

    account1.show();

    cout << account1.get_name() << ": " << account1.get_balance() << "\n";
    cout << account2.get_name() << ": " << account2.get_balance();
    return 0;
}