#include <iostream>
struct antarctice_years_end{
    int year;
};
int main() {
    using namespace std;
    antarctice_years_end s01, s02, s03;
    s01.year = 1998;
    antarctice_years_end * pa = &s02;
    pa -> year = 1999;

    antarctice_years_end trio[3];
    trio[0].year = 2003;

    std::cout << trio->year << std::endl;

    const antarctice_years_end * arp[3] = {&s01, &s02, &s03};
    std::cout << arp[1] -> year << std::endl;
    const antarctice_years_end ** ppb = arp;
    std::cout << (*ppb) -> year << std::endl;
    std::cout << (*(ppb + 1)) -> year << std::endl;
    return 0;
}