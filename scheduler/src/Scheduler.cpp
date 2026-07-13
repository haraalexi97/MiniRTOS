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

    void Scheduler::RunNextTask()
    {
        if (m_tasks.empty())
        {
            std::cout << "No tasks available.\n";
            return;
        }

        const Task* highest = &m_tasks[0];

        for (const auto& task : m_tasks)
        {
            if (task.GetPriority() > highest->GetPriority())
            {
                highest = &task;
            }
        }

        std::cout << "\n=============================\n";
        std::cout << "Running Highest Priority Task\n";
        std::cout << "=============================\n\n";

        highest->PrintInfo();
    }
}