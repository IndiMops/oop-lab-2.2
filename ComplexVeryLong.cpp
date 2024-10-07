// ComplexVeryLong.cpp
#include "ComplexVeryLong.h"

// Конструктор
ComplexVeryLong::ComplexVeryLong(const VeryLong& r, const VeryLong& i)
    : real(r), imag(i) {}

// Оператор виводу
std::ostream& operator<<(std::ostream& out, const ComplexVeryLong& c) {
    out << c.real;
    if (c.imag >= VeryLong("0")) {
        out << " + " << c.imag << "i";
    } else {
        out << " - " << -(c.imag) << "i";
    }
    return out;
}

// Оператор додавання
ComplexVeryLong ComplexVeryLong::operator+(const ComplexVeryLong& other) const {
    VeryLong realPart = real + other.real;
    VeryLong imagPart = imag + other.imag;
    return ComplexVeryLong(realPart, imagPart);
}

// Оператор віднімання
ComplexVeryLong ComplexVeryLong::operator-(const ComplexVeryLong& other) const {
    VeryLong realPart = real - other.real;
    VeryLong imagPart = imag - other.imag;
    return ComplexVeryLong(realPart, imagPart);
}

// Оператор множення
ComplexVeryLong ComplexVeryLong::operator*(const ComplexVeryLong& other) const {
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    VeryLong realPart = (real * other.real) - (imag * other.imag);
    VeryLong imagPart = (real * other.imag) + (imag * other.real);
    return ComplexVeryLong(realPart, imagPart);
}

// Оператор ділення
ComplexVeryLong ComplexVeryLong::operator/(const ComplexVeryLong& other) const {
    // (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
    VeryLong denominator = (other.real * other.real) + (other.imag * other.imag);
    
    if (denominator == VeryLong("0")) {
        throw std::invalid_argument("Ділення на нуль");
    }

    VeryLong realPart = (real * other.real + imag * other.imag) / denominator;
    VeryLong imagPart = (imag * other.real - real * other.imag) / denominator;
    
    return ComplexVeryLong(realPart, imagPart);
}


