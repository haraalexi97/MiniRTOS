#pragma once

#include <string>
#include <cstdint>
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

        int GetId() const;
        const std::string& GetName() const;
        int GetPriority() const;

        TaskState GetState() const;
        void SetState(TaskState state);
        void SetWakeTick(std::uint64_t tick);
        std::uint64_t GetWakeTick() const;

    private:
        int m_id;
        std::string m_name;
        int m_priority;
        TaskState m_state;
        std::uint64_t m_wakeTick;
    };
}