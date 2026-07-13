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
        m_state(TaskState::Ready)
        {
        }

        void Task::PrintInfo() const
        {
            std::cout
                << "Task ID: " <<m_id << '\n'
                << "Task Name: " << m_name << '\n'
                << "Task Priority: " << m_priority << '\n'; 
        }
    }


