#ifndef ESSENTIAL_C___01_H
#define ESSENTIAL_C___01_H


class Cow {
    char name[20];
    char *hobby;
    double weight;
public:
    Cow();

    Cow(const char *nm, const char *ho, double wt);

    Cow(const Cow &c);

    ~Cow();

    Cow &operator=(const Cow &c);

    void ShowCow() const;
};

#endif //01_H
