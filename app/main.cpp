#include "Scheduler.hpp"

int main()
{
    MiniRTOS::Scheduler scheduler;

    scheduler.CreateTask(1, "Blink LED", 3);
    scheduler.CreateTask(2, "Read Sensor", 5);
    scheduler.CreateTask(3, "UART", 2);

    scheduler.ListTasks();

    scheduler.RunNextTask();

    return 0;
}