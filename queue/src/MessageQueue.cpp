#include "MessageQueue.hpp"

namespace MiniRTOS
{
    bool MessageQueue::Send(int message)
    {
        if (IsFull())
        {
            return false;
        }

        m_queue.push(message);

        return true;
    }

    bool MessageQueue::Receive(int& message)
    {
        if (IsEmpty())
        {
            return false;
        }

        message = m_queue.front();

        m_queue.pop();

        return true;
    }

    bool MessageQueue::IsEmpty() const
    {
        return m_queue.empty();
    }

    bool MessageQueue::IsFull() const
    {
        return m_queue.size() >= MAX_SIZE;
    }
}