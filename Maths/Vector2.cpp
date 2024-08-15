#include "Vector2.h"

#include <iostream>

Vector2::~Vector2()
{
    std::cout << "Destroying Vector2\n";
}

Vector2 Vector2::operator+(const Vector2& vector2) const
{
    return {x + vector2.x, y + vector2.y};
}

Vector2 Vector2::operator-(const Vector2& vector2) const
{
    return {x - vector2.x, y - vector2.y};
}
