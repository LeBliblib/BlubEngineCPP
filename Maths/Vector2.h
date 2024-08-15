#pragma once

struct Vector2 {
    float x{};
    float y{};

    Vector2() = default;
    Vector2(const float x, const float y) : x(x), y(y) {}
    Vector2(const Vector2& other) = default;

    ~Vector2();

    Vector2 operator+(const Vector2& vector2) const;
    Vector2 operator-(const Vector2& vector2) const;
};
