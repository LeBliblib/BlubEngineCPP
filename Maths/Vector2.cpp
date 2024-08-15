#include "Vector2.h"
#include "Vector2Int.h"

Vector2::Vector2(const Vector2Int& other) : x(static_cast<float>(other.x)), y(static_cast<float>(other.y)) {}

Vector2 Vector2::operator+(const Vector2& vector2) const
{
    return {x + vector2.x, y + vector2.y};
}

Vector2 Vector2::operator-(const Vector2& vector2) const
{
    return {x - vector2.x, y - vector2.y};
}

Vector2 Vector2::operator*(float factor) const
{
    return {x * factor, y * factor};
}

Vector2 Vector2::operator/(float factor) const
{
    return {x / factor, y / factor};
}
Vector2& Vector2::operator*=(float factor)
{
    x *= factor;
    y *= factor;
    return *this;
}
Vector2& Vector2::operator/=(float factor)
{
    x /= factor;
    y /= factor;
    return *this;
}

Vector2 Vector2::operator*(const Vector2& factor) const
{
    return {x * factor.x, y * factor.y};
}

Vector2& Vector2::operator*=(const Vector2& factor)
{
    x *= factor.x;
    y *= factor.y;
    return *this;
}
