#include <iostream>

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    Time(int h, int m = 0);

    friend Time operator+(const Time &t1, const Time &t2);

    friend Time operator-(const Time &t1, const Time &t2);

    friend Time operator*(const Time &t, double n);

};

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

Time operator+(const Time &t1, const Time &t2) {
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time &t1, const Time &t2) {
    Time diff;
    int tot1, tot2;
    tot1 = t1.minutes + 60 * t1.hours;
    tot2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time operator*(const Time &t, double n) {
    Time result;
    long totalnimures = t.hours * n * 60 + t.minutes * n;
    result.hours = totalnimures / 60;
    result.minutes = totalnimures % 60;
    return result;
}