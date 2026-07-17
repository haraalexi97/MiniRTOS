#include "Scheduler.hpp"

#include <iostream>
#include <stdexcept>

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

    const Task* Scheduler::SelectNextTask()
    {
        if (m_tasks.empty())
        {
            return nullptr;
        }

        // Find the highest READY priority
        int highestPriority = -1;

        for (const auto& task : m_tasks)
        {
            if (task.GetState() == TaskState::Ready &&
                task.GetPriority() > highestPriority)
            {
                highestPriority = task.GetPriority();
            }
        }

        if (highestPriority == -1)
        {
            return nullptr;
        }

        // Round Robin among highest-priority READY tasks
        const std::size_t count = m_tasks.size();

        for (std::size_t offset = 1; offset <= count; ++offset)
        {
            std::size_t index =
                (m_lastScheduledIndex + offset) % count;

            if (m_tasks[index].GetState() == TaskState::Ready &&
                m_tasks[index].GetPriority() == highestPriority)
            {
                m_lastScheduledIndex = index;
                return &m_tasks[index];
            }
        }

        return nullptr;
    }

    void Scheduler::RunNextTask()
    {
        const Task* task = SelectNextTask();

        if (task == nullptr)
        {
            std::cout << "\nNo READY tasks found.\n";
            return;
        }

        std::cout << "\n=============================\n";
        std::cout << "Running Highest Priority READY Task\n";
        std::cout << "=============================\n\n";

        task->PrintInfo();
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

    Task& Scheduler::GetTask(int id)
    {
        for (auto& task : m_tasks)
        {
            if (task.GetId() == id)
            {
                return task;
            }
        }

        throw std::runtime_error("Task not found");
    }
}