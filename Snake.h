#ifndef SNAKE_H
#define SNAKE_H

#include "Point.h"
#include <vector>
class Snake {
    public:
        Point pos;
        int width;
        int height;
        int length;
        Point* body;

        Snake(int width, int height);
        ~Snake();

        void propagate();
        bool checkCollision();

        int getY();
        int getX();

        void setY(int y);
        void setX(int x);
};

Snake::Snake(int width, int height) {
    this->width = width;
    this->height = height;
    this->length = 1;
    this->pos = Point();
    this->pos.randomize(width, height);
    this->body = new Point[width*height];
    this->body[0].x = this->pos.x;
    this->body[0].y = this->pos.y;
}

Snake::~Snake() {
    delete[] body;
}

void Snake::propagate() {
    for (int i = length - 1; i > 0; i--) {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }
    body[0].x = pos.x;
    body[0].y = pos.y;
}

bool Snake::checkCollision() {
    if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height) {
        return true;
    }
    for (int i = 1; i < length; i++) {
        if (body[i].x == pos.x && body[i].y == pos.y) {
            return true;
        }
    }
    return false;
}

int Snake::getY() {
    return this->pos.y;
}

int Snake::getX() {
    return this->pos.x;
}

void Snake::setY(int y) {
    this->pos.y = y;
}

void Snake::setX(int x) {
    this->pos.x = x;
}

#endif