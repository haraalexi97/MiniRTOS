#include <iostream>

#include "Scheduler.hpp"
#include "TickTimer.hpp"

int main()
{
    MiniRTOS::Scheduler scheduler;
    MiniRTOS::TickTimer timer;

    scheduler.CreateTask(1, "Check Water Level", 5);
    scheduler.CreateTask(2, "Motor Control", 5);
    scheduler.CreateTask(3, "Bluetooth", 2);

    scheduler.ListTasks();

    for (int i = 0; i < 6; i++)
    {
        timer.Tick();

        std::cout
            << "\n========== TICK "
            << timer.GetTickCount()
            << " ==========\n";

        scheduler.RunNextTask();
    }

    return 0;
}