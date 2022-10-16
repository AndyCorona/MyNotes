#ifndef BRASS_H
#define BRASS_H

#include <string>

class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;
public:

    Brass(const std::string &s = "Nullbody", long an = -1, double balance = 0.0);

    void Deposit(double amt);

    double Balance() const;

    virtual void Withdraw(double amt);

    virtual void ViewAcct() const;

    virtual ~Brass(){};
};


class BrassPlus : public Brass {
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);

    BrassPlus(const Brass &bs, double ml = 500, double r = 0.11125);

    virtual void ViewAcct() const;

    virtual void Withdraw(double amt);

    void ResetMax(double maxLoan) {
        this->maxLoan = maxLoan;
    }

    void ResetRate(double rate) {
        this->rate = rate;

    }

    void ResetOwes() {
        this->owesBank = 0;
    }
};

#endif //BRASS_H
