#pragma once

#include <queue>

namespace MiniRTOS
{
    class MessageQueue
    {
    public:
        bool Send(int message);

        bool Receive(int& message);

        bool IsEmpty() const;

        bool IsFull() const;

    private:
        static constexpr std::size_t MAX_SIZE = 5;

        std::queue<int> m_queue;
    };
}