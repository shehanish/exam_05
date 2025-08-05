#include <iostream>

class vect2 {
private:
    int x, y;

public:
    vect2() : x(0), y(0) {}; // Default constructor
    vect2(int x, int y) : x(x), y(y) {}; // Parameterized constructor
    vect2(const vect2& oth) : x(oth.x), y(oth.y) {}; // Copy constructor

    vect2& operator=(const vect2& oth) { // Copy assignment operator
        if (*this != oth)  {
            x = oth.x;
            y = oth.y;
        }
        return *this;
    }

    int& operator[](int i) { // Subscript operator (non-const)
        return (i == 0 ? x : y);
    }

    int operator[](int i) const { // Subscript operator (const)
        return (i == 0 ? x : y);
    }

    friend std::ostream& operator<<(std::ostream& os, const vect2& v) { // Output stream operator
        os << "{" << v[0] << ", " << v[1] << "}";
        return os;
    }

    vect2 operator++(int) { // Post-increment operator
        vect2 tmp = *this;
        x++;
        y++;
        return tmp;
    }

    vect2& operator++() { // Pre-increment operator
        x++;
        y++;
        return *this;
    }

    vect2 operator--(int) { // Post-decrement operator
        vect2 tmp = *this;
        x--;
        y--;
        return tmp;
    }

    vect2& operator--() { // Pre-decrement operator
        x--;
        y--;
        return *this;
    }

    vect2& operator+=(const vect2& oth) { // Addition assignment operator
        x += oth.x;
        y += oth.y;
        return *this;
    }

    vect2& operator-=(const vect2& oth) { // Subtraction assignment operator
        x -= oth.x;
        y -= oth.y;
        return *this;
    }

    vect2 operator+(const vect2& oth) const { // Addition operator
        return vect2(x + oth.x, y + oth.y);
    }

    vect2 operator-(const vect2& oth) const { // Subtraction operator
        return vect2(x - oth.x, y - oth.y);
    }

    vect2 operator*(int s) const { // Scalar multiplication operator
        return vect2(x * s, y * s);
    }

    friend vect2 operator*(int s, const vect2& v) { // Scalar multiplication (commutative)
        return vect2(v.x * s, v.y * s);
    }

    vect2& operator*=(int s) { // Scalar multiplication assignment operator
        x *= s;
        y *= s;
        return *this;
    }

    vect2 operator-() { // Unary minus operator
        return vect2(-x, -y);
    }

    bool operator==(const vect2& oth) { // Equality operator
        return (x == oth.x && y == oth.y);
    }

    bool operator!=(const vect2& oth) { // Inequality operator
        return !(x == oth.x && y == oth.y);
    }
};
