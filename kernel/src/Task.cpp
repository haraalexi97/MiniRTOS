#include "Task.hpp"

#include <iostream>

namespace MiniRTOS
{
    Task::Task(
        int id,
        const std::string& name,
        int priority)
        :
        m_id(id),
        m_name(name),
        m_priority(priority),
        m_state(TaskState::Ready),
        m_wakeTick(0)
    {
    }

    void Task::PrintInfo() const
    {
        std::cout
            << "Task ID: " << m_id << '\n'
            << "Task Name: " << m_name << '\n'
            << "Task Priority: " << m_priority << '\n';

        std::cout << "Task State: ";

        switch (m_state)
        {
        case TaskState::Ready:
            std::cout << "READY";
            break;

        case TaskState::Running:
            std::cout << "RUNNING";
            break;

        case TaskState::Blocked:
            std::cout << "BLOCKED";
            break;

        case TaskState::Suspended:
            std::cout << "SUSPENDED";
            break;
        }

        std::cout << "\n";
    }

    int Task::GetId() const
    {
        return m_id;
    }

    const std::string& Task::GetName() const
    {
        return m_name;
    }

    int Task::GetPriority() const
    {
        return m_priority;
    }

    TaskState Task::GetState() const
    {
        return m_state;
    }

    void Task::SetState(TaskState state)
    {
        m_state = state;
    }
    void Task::SetWakeTick(std::uint64_t tick)
    {
        m_wakeTick = tick;
    }
    std::uint64_t Task::GetWakeTick() const
    {
        return m_wakeTick;
    }
}