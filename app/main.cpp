#include <iostream>

#include "Scheduler.hpp"
#include "TickTimer.hpp"
#include "MessageQueue.hpp"

int main()
{
    std::cout << "***** NEW MAIN EXECUTED *****\n";
    MiniRTOS::Scheduler scheduler;
    MiniRTOS::TickTimer timer;
    MiniRTOS::MessageQueue queue;

    scheduler.CreateTask(1, "Check Water Level", 5);
    scheduler.CreateTask(2, "Motor Control", 5);
    scheduler.CreateTask(3, "Bluetooth", 2);

    scheduler.ListTasks();

    for (int i = 0; i < 10; ++i)
    {
        timer.Tick();

        if (timer.GetTickCount() == 1)
        {
            std::cout << "\nWater Level Task: Water tank FULL\n";
            if (queue.Send(100))
            {
                std::cout << "Message sent to queue.\n";
            }
        }

        std::cout
            << "\n========== TICK "
            << timer.GetTickCount()
            << " ==========\n";

        // At Tick 2, delay Water Level for 3 ticks
        if (timer.GetTickCount() == 2)
        {
            std::cout
                << "\nDelaying 'Check Water Level' for 3 ticks\n\n";

            scheduler.DelayTask(
                1,
                timer.GetTickCount(),
                3);
        }

        // Wake any delayed tasks whose time has arrived
        scheduler.UpdateDelayedTasks(timer.GetTickCount());

        int message;
        if (queue.Receive(message))
        {
            std::cout << "Motor Task received message: "
            << message
            << '\n';
        }
        scheduler.RunNextTask();
    }

    return 0;
}