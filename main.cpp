// main.cpp
#include <iostream>
#include "VeryLong.h"
#include "ComplexVeryLong.h"
#include "menu.h"
#include <windows.h>
#include <string>

using namespace std;

void addComplex() {
    // Буфер
    string breal1;
    string bimag1;
    string breal2;
    string bimag2;
    cout << "Додавання комплексних чисел" << endl;
    cout << "Введіть реальну частину 1-о числа: ";
    cin >> breal1;
    VeryLong real1(breal1);

    cout << "Введіть уявну частину 1-о числа: ";
    cin >> bimag1;
    VeryLong imag1(bimag1);

    cout << "\nВведіть реальну частину 2-о числа: ";
    cin >> breal2;
    VeryLong real2(breal2);

    cout << "Введіть уявну частину 2-о числа: ";
    cin >> bimag2;
    VeryLong imag2(bimag2);

    ComplexVeryLong complex1(real1, imag1);
    ComplexVeryLong complex2(real2, imag2);

    ComplexVeryLong sum = complex1 + complex2;
    std::cout << "Результат: " << sum << std::endl;
}

void difComplex() {
    // Буфер
    string breal1;
    string bimag1;
    string breal2;
    string bimag2;

    cout << "Додавання комплексних чисел" << endl;
    cout << "Введіть реальну частину 1-о числа: ";
    cin >> breal1;
    VeryLong real1(breal1);

    cout << "Введіть уявну частину 1-о числа: ";
    cin >> bimag1;
    VeryLong imag1(bimag1);

    cout << "\nВведіть реальну частину 2-о числа: ";
    cin >> breal2;
    VeryLong real2(breal2);

    cout << "Введіть уявну частину 2-о числа: ";
    cin >> bimag2;
    VeryLong imag2(bimag2);

    ComplexVeryLong complex1(real1, imag1);
    ComplexVeryLong complex2(real2, imag2);

    ComplexVeryLong sum = complex1 - complex2;
    std::cout << "Результат: " << sum << std::endl;
}

void multyComplex() {
    // Буфер
    string breal1;
    string bimag1;
    string breal2;
    string bimag2;

    cout << "Додавання комплексних чисел" << endl;
    cout << "Введіть реальну частину 1-о числа: ";
    cin >> breal1;
    VeryLong real1(breal1);

    cout << "Введіть уявну частину 1-о числа: ";
    cin >> bimag1;
    VeryLong imag1(bimag1);

    cout << "\nВведіть реальну частину 2-о числа: ";
    cin >> breal2;
    VeryLong real2(breal2);

    cout << "Введіть уявну частину 2-о числа: ";
    cin >> bimag2;
    VeryLong imag2(bimag2);

    ComplexVeryLong complex1(real1, imag1);
    ComplexVeryLong complex2(real2, imag2);

    ComplexVeryLong sum = complex1 * complex2;
    std::cout << "Результат: " << sum << std::endl;
}

void divComplex() {
    // Буфер
    string breal1;
    string bimag1;
    string breal2;
    string bimag2;

    cout << "Додавання комплексних чисел" << endl;
    cout << "Введіть реальну частину 1-о числа: ";
    cin >> breal1;
    VeryLong real1(breal1);

    cout << "Введіть уявну частину 1-о числа: ";
    cin >> bimag1;
    VeryLong imag1(bimag1);

    cout << "\nВведіть реальну частину 2-о числа: ";
    cin >> breal2;
    VeryLong real2(breal2);

    cout << "Введіть уявну частину 2-о числа: ";
    cin >> bimag2;
    VeryLong imag2(bimag2);

    ComplexVeryLong complex1(real1, imag1);
    ComplexVeryLong complex2(real2, imag2);

    ComplexVeryLong sum = complex1 / complex2;
    std::cout << "Результат: " << sum << std::endl;
}

void magicButton() {
    INPUT inputs[4] = {};

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'D';
    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 'D';
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_LWIN;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(4, inputs, sizeof(INPUT));
}


int main() {
    Menu mainMenu("Головне меню");
    mainMenu.addItem("Додавання комплексних чисел", addComplex);
    mainMenu.addItem("Віднімання комплексних чисел", difComplex);
    mainMenu.addItem("Множення комплексних чисел", multyComplex);
    mainMenu.addItem("Ділення комплексних чисел", divComplex);
    mainMenu.addItem("Пункт, який не вибирають", magicButton);

    mainMenu.handleInput();

    return 0;
}
