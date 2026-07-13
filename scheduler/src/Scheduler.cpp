#include "Scheduler.hpp"
#include <iostream>

namespace MiniRTOS
{
    void Scheduler::CreateTask(
        int id,
        const std::string& name,
        int priority)
        {
            m_tasks.emplace_back(id, name, priority);
        }

        void Scheduler::ListTasks() const
        {
            std::cout << "\n==== Task List ====\n\n";

            for (const auto& task : m_tasks)
            {
                task.PrintInfo();
                std::cout << '\n';
            }
        }
}