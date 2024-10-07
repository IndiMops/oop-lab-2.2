// VeryLong.cpp
#include "VeryLong.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

// Конструктор
VeryLong::VeryLong(std::string num) : number(num), isNegative(false) {
    if (num[0] == '-') {
        isNegative = true;
        number = num.substr(1);  // Відкидаємо мінус
    }
}

// Оператор виводу
std::ostream& operator<<(std::ostream& out, const VeryLong& v) {
    // Якщо число від'ємне, виводимо мінус
    if (v.isNegative) {
        out << "-";
    }
    // Виводимо саме число
    out << v.number;
    return out;
}


// Оператор додавання
VeryLong VeryLong::operator+(const VeryLong& other) const {
    // Якщо одне число від'ємне, а інше додатне, то виконуємо віднімання
    if (isNegative && !other.isNegative) {
        VeryLong temp = *this;
        temp.isNegative = false;
        return other - temp;
    }
    if (!isNegative && other.isNegative) {
        VeryLong temp = other;
        temp.isNegative = false;
        return *this - temp;
    }

    std::string num1 = number;
    std::string num2 = other.number;

    // Переконуємось, що num1 завжди більше або дорівнює за розміром
    if (num1.length() < num2.length()) {
        std::swap(num1, num2);
    }

    std::string result = "";
    int carry = 0;

    // Розвертаємо рядки для зручності додавання
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    // Додаємо цифри по одній
    for (size_t i = 0; i < num1.length(); ++i) {
        int digit1 = num1[i] - '0';
        int digit2 = (i < num2.length()) ? num2[i] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    // Додаємо залишковий переніс
    if (carry) {
        result.push_back(carry + '0');
    }

    // Повертаємо результат в нормальний порядок
    std::reverse(result.begin(), result.end());

    VeryLong sumResult(result);
    sumResult.isNegative = isNegative; // Якщо обидва числа від'ємні
    return sumResult;
}

// Оператор віднімання
VeryLong VeryLong::operator-(const VeryLong& other) const {
    // Якщо одне число від'ємне, то використовуємо додавання
    if (isNegative && !other.isNegative) {
        VeryLong temp = *this;
        temp.isNegative = false;
        return -(temp + other);  // Викликаємо унарний мінус
    }
    if (!isNegative && other.isNegative) {
        VeryLong temp = other;
        temp.isNegative = false;
        return *this + temp;
    }

    // Якщо обидва числа мають однаковий знак
    bool resultNegative = false;
    std::string num1 = number;
    std::string num2 = other.number;

    // Визначаємо, яке число більше
    if (isSmaller(num1, num2)) {
        std::swap(num1, num2);
        resultNegative = true;
    }

    std::string result = subtractStrings(num1, num2);

    VeryLong subResult(result);
    subResult.isNegative = resultNegative;
    return subResult;
}

// Оператор ділення (просте ділення без залишку)
VeryLong VeryLong::operator/(const VeryLong& other) const {
    if (other.number == "0") {
        throw std::invalid_argument("Ділення на нуль");
    }

    std::string result;
    std::string dividend = number;
    std::string divisor = other.number;

    std::string current = ""; 
    int idx = 0;
    
    while (idx < dividend.length()) {
        current += dividend[idx++];
        // Поступово збираємо число зі строки, поки воно не стане більшим або рівним дільнику
        int quotient = 0;
        
        // Симулюємо ділення вручну
        while (current.length() > divisor.length() || 
              (current.length() == divisor.length() && current >= divisor)) {
            current = subtractStrings(current, divisor);  // Віднімаємо дільник
            quotient++;
        }

        result += std::to_string(quotient);  // Додаємо частку
    }

    // Видаляємо провідні нулі
    size_t nonZeroPos = result.find_first_not_of('0');
    result = result.substr(nonZeroPos == std::string::npos ? 0 : nonZeroPos);

    return VeryLong(result.empty() ? "0" : result);
}



// Унарний мінус
VeryLong VeryLong::operator-() const {
    VeryLong result = *this;
    result.isNegative = !isNegative;  // Змінюємо знак числа
    return result;
}

// Допоміжний метод для перевірки, чи є одне число меншим за інше
bool VeryLong::isSmaller(const std::string& num1, const std::string& num2) const {
    int len1 = num1.length();
    int len2 = num2.length();

    if (len1 < len2) return true;
    if (len1 > len2) return false;

    for (int i = 0; i < len1; ++i) {
        if (num1[i] < num2[i]) return true;
        if (num1[i] > num2[i]) return false;
    }
    return false;
}

// Допоміжний метод для виконання віднімання рядків
std::string VeryLong::subtractStrings(const std::string& str1, const std::string& str2) const {
    std::string result = "";
    int carry = 0;

    std::string num1 = str1;
    std::string num2 = str2;
    
    // Додаємо провідні нулі до num2, щоб їх довжини збігалися
    while (num2.length() < num1.length()) {
        num2 = "0" + num2;
    }

    // Віднімаємо цифри справа наліво
    for (int i = num1.length() - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0' + carry;

        if (digit1 < digit2) {
            digit1 += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result = std::to_string(digit1 - digit2) + result;
    }

    // Видаляємо провідні нулі
    size_t nonZeroPos = result.find_first_not_of('0');
    result = result.substr(nonZeroPos == std::string::npos ? 0 : nonZeroPos);

    return result.empty() ? "0" : result;

    // Перевертаємо результат для правильного порядку
    std::reverse(result.begin(), result.end());
    return result;
}

// Оператор множення
// Оператор множення
VeryLong VeryLong::operator*(const VeryLong& other) const {
    std::string num1 = number;
    std::string num2 = other.number;

    // Якщо одне з чисел — 0, результат також 0
    if (num1 == "0" || num2 == "0") {
        return VeryLong("0");
    }

    // Результат множення може мати максимальну довжину len1 + len2
    std::vector<int> result(num1.length() + num2.length(), 0);

    // Множимо цифри кожного числа
    for (int i = num1.length() - 1; i >= 0; --i) {
        for (int j = num2.length() - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');  // Множимо цифри
            int sum = mul + result[i + j + 1];  // Додаємо до поточної позиції

            result[i + j + 1] = sum % 10;  // Зберігаємо останню цифру
            result[i + j] += sum / 10;     // Додаємо перенос до наступної позиції
        }
    }

    // Перетворюємо результат з вектора в рядок
    std::string resultStr;
    bool leadingZero = true;
    for (int digit : result) {
        if (digit == 0 && leadingZero) {
            continue;  // Пропускаємо провідні нулі
        }
        leadingZero = false;
        resultStr.push_back(digit + '0');  // Додаємо цифру до рядка
    }

    // Якщо результат пустий, це означає, що число є нулем
    if (resultStr.empty()) {
        resultStr = "0";
    }

    VeryLong mulResult(resultStr);

    // Якщо знаки різні, результат від'ємний
    mulResult.isNegative = (isNegative != other.isNegative);

    return mulResult;
}

// Оператор рівності для VeryLong
bool VeryLong::operator==(const VeryLong& other) const {
    return (isNegative == other.isNegative) && (number == other.number);
}

// Оператор >= для VeryLong
bool VeryLong::operator>=(const VeryLong& other) const {
    if (isNegative && !other.isNegative) return false;
    if (!isNegative && other.isNegative) return true;

    // Якщо обидва числа від'ємні, порівнюємо, але перевертаємо логіку
    if (isNegative && other.isNegative) {
        return !isSmaller(number, other.number);
    }

    // Якщо обидва числа додатні
    return !isSmaller(number, other.number);
}


