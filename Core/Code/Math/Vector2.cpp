//
// Created by mwlky on 6/1/24.
//

#include <cmath>
#include "Vector2.h"

namespace Engine {
    Vector2::Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector2 &Vector2::Add(const Vector2 &vec) {
        this->x += vec.x;
        this->y += vec.y;

        return *this;
    }

    Vector2 &Vector2::Subtract(const Vector2 &vec) {
        this->x -= vec.x;
        this->y -= vec.y;

        return *this;
    }

    Vector2 &Vector2::Multiply(const Vector2 &vec) {
        this->x *= vec.x;
        this->y *= vec.y;

        return *this;
    }

    Vector2 &Vector2::Divide(const Vector2 &vec) {
        this->x /= vec.x;
        this->y /= vec.y;

        return *this;
    }

    Vector2 &operator+(Vector2 &v1, const Vector2 &v2) {
        return v1.Add(v2);
    }

    Vector2 &operator-(Vector2 &v1, const Vector2 &v2) {
        return v1.Subtract(v2);
    }

    Vector2 &operator*(Vector2 &v1, const Vector2 &v2) {
        return v1.Multiply(v2);
    }

    Vector2 &operator/(Vector2 &v1, const Vector2 &v2) {
        return v1.Divide(v2);
    }

    Vector2 &Vector2::operator+=(const Vector2 &vec) {
        return this->Add(vec);
    }

    Vector2 &Vector2::operator-=(const Vector2 &vec) {
        return this->Subtract(vec);
    }

    Vector2 &Vector2::operator*=(const Vector2 &vec) {
        return this->Multiply(vec);
    }

    Vector2 &Vector2::operator/=(const Vector2 &vec) {
        return this->Divide(vec);
    }

    std::ostream &operator<<(std::ostream &stream, const Vector2 &vec) {
        stream << "(" << vec.x << "," << vec.y << ")" << std::endl;
        return stream;
    }

    Vector2 &Vector2::operator*(const int &i) {
        this->x *= i;
        this->y *= i;

        return *this;
    }

    Vector2 &Vector2::Zero() {
        this->x = 0;
        this->y = 0;

        return *this;
    }

    Vector2 &Vector2::Right() {
        this->x = 1;
        this->y = 0;

        return *this;
    }

    Vector2 &Vector2::Left() {
        this->x = -1;
        this->y = 0;

        return *this;
    }

    Vector2 &Vector2::Up() {
        this->x = 0;
        this->y = 1;

        return *this;
    }

    Vector2 &Vector2::Down() {
        this->x = 0;
        this->y = -1;

        return *this;
    }

    Vector2 Vector2::Absolute(const Vector2 &vec) {
        return Vector2(fabs(vec.x), fabs(vec.y));
    }

    bool Vector2::operator==(const Vector2 &vec) {
        return this->x == vec.x && this->y == vec.y;
    }

    bool Vector2::operator!=(const Vector2 &vec) {
        return this->x != vec.x || this->y != vec.y;
    }
} // Engine