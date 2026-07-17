#pragma once

#include <vector>
#include <string>
#include <cstddef>

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

        const Task* SelectNextTask();

        void RunNextTask();

        void BlockTask(int id);

        void ReadyTask(int id);

        Task& GetTask(int id);

    private:
        std::vector<Task> m_tasks;
        std::size_t m_lastScheduledIndex = 0;
    };
}