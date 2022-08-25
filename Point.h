#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
    int x;
    int y;

    Point();

    Point(int x, int y);

    void randomize(int xlim, int ylim);
};

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::randomize(int xlim, int ylim) {
    this->x = rand() % xlim;
    this->y = rand() % ylim;
}

#endif