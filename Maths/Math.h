#pragma once
#include <cmath>

class Math
{
public:
    static int Round(const float f)
    {
        return static_cast<int>(round(f));
    }
};
