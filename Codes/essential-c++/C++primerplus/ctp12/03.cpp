#include <iostream>
#include "03.h"

Stock::Stock() {
    company = new char[8];
    strcpy(company, "no name");
    company[8] = '\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *c, long n, double pr) {
    int len = strlen(c);
    company = new char[len + 1];
    strcpy(company, c);
    if (n < 0) {
        std::cout << "Number of shares cannot be negative: "
                  << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::Stock(const Stock &s) {
    int len = strlen(s.company);
    company = new char[len + 1];
    strcpy(company, s.company);
}

Stock &Stock::operator=(const Stock &s) {
    if (this == &s) {
        return *this;
    }

    int len = strlen(s.company);
    company = new char[len + 1];
    strcpy(company, s.company);
    return *this;
}

Stock::~Stock() {
    delete[] company;
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares purchased cannot be negative. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}


void Stock::sell(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares sold cannot be negative. "
                  << "Transaction is aborted.\n";
    } else if (num > shares) {
        std::cout << "You cannot sell more than you have! "
                  << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

ostream &operator<<(ostream &os, const Stock &s) {
    using std::ios_base;
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);
    os << "Company: " << s.company
       << " Shares: " << s.shares << '\n';
    os << " Shares Price: $" << s.share_val;
    os.precision(2);
    std::cout << "hello";
    os << " Total Worth: $" << s.total_val << '\n';
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    return os;
}

const Stock &Stock::topval(const Stock &s) const {
    if (s.total_val > total_val) {
        return s;
    } else {
        return *this;
    }
}

int main() {
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0);
        cout << stock1;
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);
        cout << stock2;
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        cout << stock1;
        cout << stock2;

        cout << "Using a constructors to create an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);
        cout << "Revised stock1:\n";
        cout << stock1;
        cout << "Done\n";
    }
    return 0;
}
