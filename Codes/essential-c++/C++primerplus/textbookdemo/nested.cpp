#include <iostream>
const int Cities = 5;
const int Years = 4;
int main() {
    using namespace std;
    const char* cities[Cities] = {
            "A",
            "B",
            "C",
            "D",
            "E",
    };
    int maxtmeps[Years][Cities] = {
            {96,100,87,101,105},
            {96,100,87,101,105},
            {96,100,87,101,105},
            {96,100,87,101,105},
    };
    cout << "Maximum temperatures for 2008 - 2011\n\n";
    for (int city = 0; city < Cities; city++) {
        cout << cities[city] << ":\t";
        for(int year = 0; year < Years; year++ ) {
            cout << maxtmeps[year][city] << "\t";
        }
        cout << endl;
    }
    return 0;
}