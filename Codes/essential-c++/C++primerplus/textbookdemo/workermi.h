#ifndef WORKERMI_H
#define WORKERMI_H


#include <string>

class Worker {
private:
    std::string fullname;
    long id;
public:
    Worker() : fullname("no one"), id(0L) {};

    Worker(const std::string &s, long n) : fullname(s), id(n) {};

    virtual  ~Worker() = 0;

    virtual void Set() = 0;

    virtual void Show() const = 0;

protected:
    virtual void Data() const;

    virtual void Get();
};


class Waiter : virtual public Worker {
private:
    int panache;

public:

    Waiter() : Worker(), panache(0) {};

    Waiter(const std::string &s, long n, int p = 0) : Worker(s, n), panache(p) {};

    Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {};

    void Set();

    void Show() const;

protected:

    void Data() const;

    void Get();
};


class Singer : virtual public Worker {
protected:
    enum {
        other, alto, contralto, soprano, bass, baritone, tenor
    };
    enum {
        Vtypes = 7
    };

    void Data() const;

    void Get();

private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {};

    Singer(const std::string &s, long n, int v = other) : Worker(s, n), voice(v) {};

    Singer(const Worker &wk, int v = other) : Worker(wk), voice(v) {};

    void Set();

    void Show() const;

};


class SingingWaiter : public Singer, public Waiter {
public:
    SingingWaiter() {};

    SingingWaiter(const std::string &s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p),
                                                                            Singer(s, n, v) {};

    SingingWaiter(const Waiter &wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v) {};

    SingingWaiter(const Singer &wt, int p = 0) : Worker(wt), Waiter(wt, p), Singer(wt) {};

    void Set();

    void Show() const;

protected:
    void Data() const;

    void Get();

};

#endif //WORKERMI_H
