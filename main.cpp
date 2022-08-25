#include<iostream>
#include<conio.h>
#include "GameFpsController.h"
#include "Utils.h"
#include "Point.h"
#include "Snake.h"

using namespace std;

bool debug = true;
double delay = 0;
int width = 20;
int height = 20;
sDirection dir = UP;
GameFpsController controller = GameFpsController();
int score = 0;
Point food = Point();
Snake snake = Snake(width, height);

void setup() {
    food.randomize(width, height);
}

void draw() {
    system("cls");
    for (int i = 0; i < height+2; i++) {
        for (int j = 0; j < width+2; j++) {
            bool found = false;
            for (int k = 0; k < snake.length; k++) {
                if (i-1 == snake.body[k].y && j-1 == snake.body[k].x) {
                    printf("*");
                    found = true;
                }
            }
            if (found) {
                continue;
            }
            if (i == 0 || i == height+1 || j == 0 || j == width +1) {
                printf("#");
            } else if (i-1 == food.y && j-1 == food.x) {
                printf("%%");
            } else {
                printf(" ");
            }
        }
        cout << endl;
    }
    if (debug) {
        printf("Time since last frame: %fms \n", delay);
        printf("\t key pressed: %d \n", dir);
        printf("pos 1: %d, %d \n", snake.body[0].x, snake.body[0].y);
        printf("snake pos: %d, %d \n", snake.pos.x, snake.pos.y);
    }   
    printf("Score: %d \n", score);
}

void input() {
    if (_kbhit()) {
        switch(_getch()) {
            case('w') :
                if (dir != DOWN) {
                    dir = UP;
                }
                break;
            case('s') :
                if (dir != UP) {
                    dir = DOWN;
                }
                break;
            case('a') :
                if (dir != RIGHT) {
                    dir = LEFT;
                }
                break;
            case('d') :
                if (dir != LEFT) {
                    dir = RIGHT;
                }
                break;
        }
    }
}

void gameOver() {
    system("cls");
    printf("Game over! \n");
    printf("Score: %d \n", score);
    printf("Press any key to exit...");
    _getch();
    exit(0);
}

void update() {
    if (snake.getX() == food.x && snake.getY() == food.y) {
        food.randomize(width, height);
        score++;
        snake.length++;
    }

    switch (dir) {
        case UP:
            snake.setY(snake.getY()-1);
            break;
        case DOWN:
            snake.setY(snake.getY()+1);
            break;
        case LEFT:
            snake.setX(snake.getX()-1);
            break;
        case RIGHT:
            snake.setX(snake.getX()+1);
            break;
        default:
            break;
    }
    snake.propagate();
    if (snake.checkCollision()) {
        gameOver();
    }
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