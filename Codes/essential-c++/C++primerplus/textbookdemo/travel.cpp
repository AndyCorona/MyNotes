#include <iostream>

struct travel_time {
    int hours;
    int min;
};
const int Min_per_hour = 60;

travel_time sum(travel_time t1, travel_time t2);

void show_time(travel_time t);

int main() {
    using namespace std;
    travel_time day1 = {5, 45};
    travel_time day2 = {4, 55};

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);
    travel_time day3 = {4, 32};
    cout << "Three-day total: ";
    show_time(sum(trip, day3));
    return 0;
}

travel_time sum(travel_time t1, travel_time t2) {
    travel_time total;

    total.min = (t1.min + t2.min) % Min_per_hour;
    total.hours = (t1.hours + t2.hours) + (t1.min + t2.min) / Min_per_hour;
    return total;
}

void show_time(travel_time t) {
    using namespace  std;
    cout << t.hours << " hours, "
    << t.min << " minutes.\n";
}