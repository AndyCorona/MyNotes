#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const std::string &s, long an, double balance) {
    fullName = s;
    accNam = an;
    balance = balance;
}

void AcctABC::Deposit(double amt) {
    if (amt < 0) {
        cout << "存款金额不能为负数，存款操作取消\n";
    } else {
        balance += amt;
    }
}

void AcctABC::Withdraw(double amt) {
    balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const {
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(AcctABC::Formatting &f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

void Brass::Withdraw(double amt) {
    if (amt < 0) {
        cout << "取款金额不能为负数，取款操作取消\n";
    } else if (amt <= Balance()) {
        AcctABC::Withdraw(amt);
    } else {
        cout << "余额不足\n";
    }
}

void Brass::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "Brass 账户名:  " << FullName() << endl;
    cout << "账户：" << AcctNum() << endl;
    cout << "余额：" << Balance() << endl;
    Restore(f);
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : AcctABC(s,an,bal){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AcctABC(ba){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "BrassPlus 账户名: " << FullName() << endl;
    cout << "账户：" << AcctNum() << endl;
    cout << "余额：" << Balance() << endl;
    cout << "最大可借款余额：$" << maxLoan << endl;
    cout << "还款金额：$" << owesBank << endl;
    cout.precision(3);
    cout << "借款利率：" << rate * 100 << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt) {
    Formatting f = SetFormat();
    double bal = Balance();
    if (amt <= bal) {
        AcctABC::Withdraw(amt);
    } else if (amt <= bal + maxLoan -owesBank) {
        double advance = amt - bal;
        owesBank += advance *(1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }else {
        cout << "超过额度\n";
    }
    Restore(f);
}