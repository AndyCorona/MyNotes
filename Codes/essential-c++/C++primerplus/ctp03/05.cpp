#include <iostream>

using namespace std;

int main() {
    long long world_population;
    cout << "Enter the world's population: ";
    cin >> world_population;
    long long us_population;
    cout << "Enter the population of the US: ";
    cin >> us_population;
    double ration = us_population * 1.0 / world_population;
    cout << "The population of the US is " << ration * 100;
    cout << " % of the world population.";

    return 0;
}