#include <iostream>
#include "sontewt1.h"

int main() {
    using std::cout;
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;
    cout << "convert to double = " << p_wt << " pounds.\n";
    cout << "convert tot int = " << int(poppins) << " pounds\n";
    return 0;
}