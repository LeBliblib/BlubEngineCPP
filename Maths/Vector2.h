#pragma once

struct Vector2 {
    int x{};
    int y{};

    Vector2() = default;
    Vector2(int x, int y) : x(x), y(y) {}
    Vector2(const Vector2& other) = default;

    ~Vector2();
};
