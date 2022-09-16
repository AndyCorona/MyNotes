#include <iostream>

using namespace std;

int main() {
    long long second;
    cout << "Enter the number of seconds:";
    cin >> second;

    const int second_per_day = 60 * 60 * 24;
    const int second_per_hour = 60 * 60;
    const int second_per_minute = 60;
    int day = second / second_per_day;
    second %= second_per_day;
    int hour = second / second_per_hour;
    second %= second_per_hour;
    int minute = second / second_per_minute;
    second %= second_per_minute;

    cout << second << " seconds = " << day << " days, ";
    cout << hour << " hours, " << minute << " minutes, ";
    cout << second << " seconds" << endl;


    return 0;
}