#include "Mutex.hpp"

namespace MiniRTOS
{
    bool Mutex::Lock()
    {
        if (m_locked)
        {
            return false;
        }

        m_locked = true;
        return true;
    }

    void Mutex::Unlock()
    {
        m_locked = false;
    }

    bool Mutex::IsLocked() const
    {
        return m_locked;
    }
}