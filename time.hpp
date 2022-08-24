#include<iostream>
#include <chrono>
#include <thread>

class GameFpsController {
    private:
        std::chrono::system_clock::time_point a;
        std::chrono::system_clock::time_point b;
    public:
        GameFpsController() {
            a = std::chrono::system_clock::now();
            b = std::chrono::system_clock::now();
        }

        void delay(int fps) {
            a = std::chrono::system_clock::now();
            std::chrono::duration<double, std::milli> work_time = a - b;

            if (work_time.count() < 200.0)
            {
                std::chrono::duration<double, std::milli> delta_ms(200.0 - work_time.count());
                auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
                std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
            }

            b = std::chrono::system_clock::now();
            std::chrono::duration<double, std::milli> sleep_time = b - a;

            // Your code here

            printf("Time: %f \n", (work_time + sleep_time).count());
        }
};