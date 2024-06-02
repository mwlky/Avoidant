#pragma once

#include <iostream>

namespace Engine {

    struct Vector2 {
    public:
        Vector2() = default;
        Vector2(float x, float y);

        float x = 0;
        float y = 0;

        friend Vector2 &operator+(Vector2 &v1, const Vector2 &v2);
        friend Vector2 &operator-(Vector2 &v1, const Vector2 &v2);
        friend Vector2 &operator*(Vector2 &v1, const Vector2 &v2);
        friend Vector2 &operator/(Vector2 &v1, const Vector2 &v2);

        Vector2 &operator+=(const Vector2 &vec);
        Vector2 &operator-=(const Vector2 &vec);
        Vector2 &operator*=(const Vector2 &vec);
        Vector2 &operator/=(const Vector2 &vec);
        bool operator==(const Vector2& vec);
        bool operator!=(const Vector2& vec);

        static Vector2 Absolute(const Vector2& vec);
        Vector2& operator*(const int& i);
        Vector2& Zero();
        Vector2& Right();
        Vector2& Left();
        Vector2& Up();
        Vector2& Down();

    private:
        Vector2 &Add(const Vector2 &vec);
        Vector2 &Subtract(const Vector2 &vec);
        Vector2 &Multiply(const Vector2 &vec);
        Vector2 &Divide(const Vector2 &vec);
    };

} // Engine

