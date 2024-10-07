// VeryLong.h
#ifndef VERYLONG_H
#define VERYLONG_H

#include <iostream>
#include <string>

class VeryLong {
private:
    std::string number;  // Число у вигляді рядка
    bool isNegative;     // Прапорець для від'ємних чисел

public:
    // Конструктори
    VeryLong(std::string num = "0");

    // Оператори виводу
    friend std::ostream& operator<<(std::ostream& out, const VeryLong& v);

    // Оператори арифметичних операцій
    VeryLong operator+(const VeryLong& other) const;  // Додавання
    VeryLong operator-(const VeryLong& other) const;  // Віднімання
    VeryLong operator/(const VeryLong& other) const;  // Ділення
    VeryLong operator*(const VeryLong& other) const;  // Множення

    bool operator==(const VeryLong& other) const;
    bool operator>=(const VeryLong& other) const;


    // Унарний мінус
    VeryLong operator-() const;

    // Допоміжні методи
    bool isSmaller(const std::string& num1, const std::string& num2) const;
    std::string subtractStrings(const std::string& num1, const std::string& num2) const;
};

#endif // VERYLONG_H
