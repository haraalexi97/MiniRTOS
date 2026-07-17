#include "TickTimer.hpp"

namespace MiniRTOS
{
    TickTimer::TickTimer()
        : m_tickCount(0)
    {
    }

    void TickTimer::Tick()
    {
        ++m_tickCount;
    }

    std::uint64_t TickTimer::GetTickCount() const
    {
        return m_tickCount;
    }
}