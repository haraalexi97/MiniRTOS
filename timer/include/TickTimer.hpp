#pragma once

#include <cstdint>

namespace MiniRTOS
{
    class TickTimer
    {
    public:
        TickTimer();

        void Tick();

        std::uint64_t GetTickCount() const;

    private:
        std::uint64_t m_tickCount;
    };
}