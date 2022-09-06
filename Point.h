//
// Created by DAVID on 06/09/2022.
//

#ifndef SNAKE_POINT_H
#define SNAKE_POINT_H

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

#endif //SNAKE_POINT_H
