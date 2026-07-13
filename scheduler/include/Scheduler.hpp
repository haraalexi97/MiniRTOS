#pragma once

#include <vector>
#include "Task.hpp"

namespace MiniRTOS
{
    class Scheduler
    {
        public:
            void CreateTask(
                int id,
                const std::string& name,
                int priority);

            void ListTasks() const;

        private:
                std::vector<Task> m_tasks;
    };
    
}
