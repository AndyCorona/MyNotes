#include <iostream>
#include "brass.h"

int main() {
    using std::cout;
    using std::endl;

    Brass Piggy("Procelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into the Hoggy Account:\n";
    Hoggy.Deposit(1000);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    cout << "Piggy account balance: $" << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Piggy Account:\n";
    Piggy.Withdraw(4200);
    cout << "Withdrawing $4200 form the Hoggy Account:\n" << endl;
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();
    return 0;
}