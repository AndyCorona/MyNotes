#ifndef MYTIME1_H
#define MYTIME1_H

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    Time(int h, int m = 0);

    void AddMin(int m);

    void AddHr(int h = 0);

    void Reset(int h = 0, int m = 0);

    Time operator+(const Time &t) const;

    void Show() const;
};

#endif //MYTIME1_H
