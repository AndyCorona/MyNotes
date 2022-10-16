#ifndef ESSENTIAL_C___03_H
#define ESSENTIAL_C___03_H
using std::ostream;

class Stock {
private:
    char *company;
    int shares;
    double share_val;
    double total_val;

    void set_tot() {
        total_val = share_val * shares;
    }

public:
    Stock();

    Stock(const char *c, long n = 0, double pr = 0.0);

    Stock (const Stock & s);

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    const Stock &topval(const Stock &s) const;

    Stock & operator=(const Stock & s);

    ~Stock();

    friend ostream &operator<<(ostream &os, const Stock &s);
};

#endif //ESSENTIAL_C___03_H
