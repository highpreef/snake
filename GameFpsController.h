//
// Created by DAVID on 06/09/2022.
// (based on https://stackoverflow.com/questions/38730273/how-to-limit-fps-in-a-loop-with-c)
//

#ifndef SNAKE_GAMEFPSCONTROLLER_H
#define SNAKE_GAMEFPSCONTROLLER_H

#include <chrono>
#include <thread>

class GameFpsController {
private:
    std::chrono::system_clock::time_point a;
    std::chrono::system_clock::time_point b;
public:
    GameFpsController();

    double delay(double milliPerFrame);
};

GameFpsController::GameFpsController() {
    a = std::chrono::system_clock::now();
    b = std::chrono::system_clock::now();
}

double GameFpsController::delay(double milliPerFrame) {
    a = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> work_time = a - b;

    if (work_time.count() < milliPerFrame)
    {
        std::chrono::duration<double, std::milli> delta_ms(milliPerFrame - work_time.count());
        auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
        std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
    }

    b = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> sleep_time = b - a;

    return (work_time + sleep_time).count();
}

#endif //SNAKE_GAMEFPSCONTROLLER_H
