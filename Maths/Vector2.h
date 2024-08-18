#pragma once

struct Vector2Int;

#pragma pack(push, 1)  // Save the current alignment and set new alignment to 1 byte

struct Vector2 {
    float x{};
    float y{};

    Vector2() = default;
    Vector2(const float x, const float y) : x(x), y(y) {}
    Vector2(const Vector2& other) = default;
    explicit Vector2(const Vector2Int& other); 
    
    Vector2 operator+(const Vector2& vector2) const;
    Vector2 operator-(const Vector2& vector2) const;

    Vector2 operator*(float factor) const;
    Vector2 operator/(float factor) const;
    
    Vector2& operator*=(float factor);
    Vector2& operator/=(float factor);

    Vector2 operator*(const Vector2& factor) const;
    Vector2& operator*=(const  Vector2& factor);
};

#pragma pack(pop)  // Restore the original alignment