// ComplexVeryLong.h
#ifndef COMPLEXVERYLONG_H
#define COMPLEXVERYLONG_H

#include "VeryLong.h"

class ComplexVeryLong {
private:
    VeryLong real;    // Дійсна частина
    VeryLong imag;    // Уявна частина

public:
    // Конструктори
    ComplexVeryLong(const VeryLong& r = VeryLong("0"), const VeryLong& i = VeryLong("0"));

    // Оператори виводу
    friend std::ostream& operator<<(std::ostream& out, const ComplexVeryLong& c);

    // Оператори арифметичних операцій
    ComplexVeryLong operator+(const ComplexVeryLong& other) const;  // Додавання
    ComplexVeryLong operator-(const ComplexVeryLong& other) const;  // Віднімання
    ComplexVeryLong operator*(const ComplexVeryLong& other) const;  // Множення
    ComplexVeryLong operator/(const ComplexVeryLong& other) const;  // Ділення
};

#endif // COMPLEXVERYLONG_H
