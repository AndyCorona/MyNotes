#ifndef COORDIN_H
#define COORDIN_H

//结构声明
struct polar{
    double distance;
    double angle;
};

struct rect {
    double x;
    double y;
};

//函数原型声明
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
