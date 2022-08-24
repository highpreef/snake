#include<iostream>
#include<conio.h>
#include "GameFpsController.h"
#include "Utils.h"

using namespace std;

bool debug = true;
double delay = 0;
const int width = 20;
const int height = 20;
sDirection dir = IDLE;
GameFpsController controller = GameFpsController();
int x, y, fx, fy, score = 0;

void setup() {
    x = width / 2;
    y = height / 2;
    fx = rand() % width;
    fy = rand() % height;
}

void draw() {
    system("cls");
    for (int i = 0; i < height+2; i++) {
        for (int j = 0; j < width+2; j++) {
            if (i == 0 || i == height+1 || j == 0 || j == width +1) {
                cout << "#";
            } else if (i-1 == y && j-1 == x) {
                cout << "*";
            } else if (i-1 == fy && j-1 == fx) {
                cout << "%";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    if (debug) {
        printf("Time since last frame: %fms \n", delay);
        printf("\t key pressed: %d \n", dir);
    }   
    printf("Score: %d \n", score);
}

void input() {
    if (_kbhit()) {
        switch(_getch()) {
            case('w') :
                dir = UP;
                break;
            case('s') :
                dir = DOWN;
                break;
            case('a') :
                dir = LEFT;
                break;
            case('d') :
                dir = RIGHT;
                break;
        }
    }
}

void update() {
    if (x == fx && y == fy) {
        fx = rand() % width;
        fy = rand() % height;
        score++;
    }

    switch (dir) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
    }
    x = (x + width) % width;
    y = (y + height) % height;
}

int main()
{

    setup();
    while (true)
    {
        delay = controller.delay(200); // 5fps
        draw();
        input();
        update();
    }

    return 0;
}