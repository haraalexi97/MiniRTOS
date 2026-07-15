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
        const Task* highest = nullptr;

        for (const auto& task : m_tasks)
        {
            if (task.GetState() != TaskState::Ready)
            {
                continue;
            }

            if (highest == nullptr ||
                task.GetPriority() > highest->GetPriority())
            {
                highest = &task;
            }
        }

        if (highest == nullptr)
        {
            std::cout << "\nNo READY tasks found.\n";
            return;
        }

        std::cout << "\n=============================\n";
        std::cout << "Running Highest Priority READY Task\n";
        std::cout << "=============================\n\n";

        highest->PrintInfo();
    }

    void Scheduler::BlockTask(int id)
    {
        for (auto& task : m_tasks)
        {
            if (task.GetId() == id)
            {
                task.SetState(TaskState::Blocked);
                return;
            }
        }
    }

    void Scheduler::ReadyTask(int id)
    {
        for (auto& task : m_tasks)
        {
            if (task.GetId() == id)
            {
                task.SetState(TaskState::Ready);
                return;
            }
        }
    }
}