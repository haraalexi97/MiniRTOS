#include "TickTimer.hpp"

namespace MiniRTOS
{
    void TickTimer::Tick()
    {
        ++m_tickCount;
    }

    std::uint64_t TickTimer::GetTickCount() const
    {
        return m_tickCount;
    }
}