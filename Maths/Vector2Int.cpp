#include "Vector2Int.h"

#include <iostream>

#include "Math.h"

Vector2Int::Vector2Int(const Vector2& other)
{
    x = Math::Round(other.x);
    y = Math::Round(other.y);
}

Vector2Int::~Vector2Int()
{
    std::cout << "Destroying Vector2\n";
}

Vector2Int Vector2Int::operator+(const Vector2Int& vector2) const
{
    return {x + vector2.x, y + vector2.y};
}

Vector2Int Vector2Int::operator-(const Vector2Int& vector2) const
{
    return {x - vector2.x, y - vector2.y};
}