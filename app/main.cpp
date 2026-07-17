#include "Scheduler.hpp"

int main()
{
    MiniRTOS::Scheduler scheduler;

    scheduler.CreateTask(1, "Check Water Level", 5);
    scheduler.CreateTask(2, "Motor Control", 5);
    scheduler.CreateTask(3, "Bluetooth", 2);

    scheduler.ListTasks();

    scheduler.RunNextTask();
    scheduler.RunNextTask();
    scheduler.RunNextTask();
    scheduler.RunNextTask();
    scheduler.RunNextTask();
    scheduler.RunNextTask();

    return 0;
}