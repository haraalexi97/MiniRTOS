#pragma once

#include<string>
#include "TaskState.hpp"

namespace MiniRTOS
{
    class Task
    {
        public:
            Task(
                int id,
                const std::string& name,
                int priority);

            void PrintInfo() const;

            int GetPriority() const;

        private:
            int m_id;
            std::string m_name;
            int m_priority;
            TaskState m_state;
    };
}
