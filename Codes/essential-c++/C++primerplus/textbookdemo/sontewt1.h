#ifndef SONTEWT1_H
#define SONTEWT1_H

class Stonewt {
private:
    enum {
        Lbs_per_stn = 14
    };
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);

    Stonewt(int stn, double lbs);

    Stonewt();

    ~Stonewt();

    void show_lbs() const;

    void show_stn() const;


    //自定义强制类型转换
    operator int() const;

    operator double() const;
};


#endif //SONTEWT1_H
