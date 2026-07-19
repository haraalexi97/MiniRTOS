#pragma once

namespace MiniRTOS
{
    class Mutex
    {
    public:
        bool Lock();

        void Unlock();

        bool IsLocked() const;

    private:
        bool m_locked = false;
    };
}