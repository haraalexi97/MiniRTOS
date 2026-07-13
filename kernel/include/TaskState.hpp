#pragma once

namespace MiniRTOS
{
    enum class TaskState
    {
        Ready,
        Running,
        Blocked,
        Suspended
    };
}