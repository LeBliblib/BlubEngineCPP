#pragma once
#include "Vector2.h"

#pragma pack(push, 1)

struct Vector2Int
{
    int x{};
    int y{};

    Vector2Int() = default;
    Vector2Int(const int x, const int y) : x(x), y(y) {}
    Vector2Int(const Vector2Int& other) = default;
    explicit Vector2Int(const Vector2& other);

    Vector2Int operator+(const Vector2Int& vector2) const;
    Vector2Int operator-(const Vector2Int& vector2) const;

    Vector2Int operator*(const int factor) const; 
    Vector2Int operator/(const int factor) const;

    Vector2Int operator/=(const int factor) const;
};

#pragma pack(pop)
