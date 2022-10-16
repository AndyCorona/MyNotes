#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();

void restore(format, precis);

Brass::Brass(const std::string &s, long an, double balance) {
    this->fullName = s;
    this->acctNum = an;
    this->balance = balance;
}

void Brass::Deposit(double amt) {
    if (amt < 0) {
        cout << "不允许存入负余额，"
             << "取消存款\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0) {
        cout << "不允许取出负存款，取消取款\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "您的取款超出您的账户余额，取款取消\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    format initialFormat = setFormat();
    precis prec = cout.precision(2);
    cout << "账户名：" << fullName << endl;
    cout << "账号：" << acctNum << endl;
    cout << "余额：" << balance << endl;
    restore(initialFormat, prec);
}


BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : Brass(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &bs, double ml, double r) : Brass(bs) {
    this->maxLoan = ml;
    this->owesBank = 0.0;
    this->rate = r;
}

void BrassPlus::ViewAcct() const {
    format initialFormat = setFormat();
    precis prec = cout.precision(2);
    //调用父类的同名方法
    Brass::ViewAcct();
    cout << "最大可借款额度：" << maxLoan << endl;
    cout << "当前欠款：" << owesBank << endl;
    cout.precision(3);
    cout << "借款利率：" << rate * 100 << endl;
    restore(initialFormat, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialFormat = setFormat();
    precis prec = cout.precision(2);
    //获取账户余额
    double bal = Balance();
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        //余额不足，从银行借款
        double advance = amt - bal;
        owesBank = advance * (1.0 + rate);
        cout << "从银行借款（本金）：" << advance << endl;
        cout << "借款所产生的利息：" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "您的借款额度已超标，取消借款\n";
    }
    restore(initialFormat, prec);
}


format setFormat() {
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}


void restore(format f, precis prec) {
    cout.setf(f, std::ios::floatfield);
    cout.precision(prec);
}


