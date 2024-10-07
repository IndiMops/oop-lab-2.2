// menu.cpp
#include "menu.h"
#include <iostream>

using namespace std;

// Реалізація MenuItem
MenuItem::MenuItem(string t, std::function<void()> a) : title(t), action(a) {}

// Реалізація класу Menu
Menu::Menu(string title, Menu* parent) : menuTitle(title), parentMenu(parent) {}

void Menu::addItem(string title, std::function<void()> action) {
    items.push_back(MenuItem(title, action));
}

void Menu::display() {
    cout << "==== " << menuTitle << " ====" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].title << endl;
    }

    if (parentMenu == nullptr) {
        cout << "0. Вийти з програми" << endl;
    } else {
        cout << "0. Назад (" << parentMenu->menuTitle << ")" << endl;
    }
}

void Menu::handleInput() {
    int choice;
    while (true) {
        display();
        cout << "Виберіть пункт: ";
        cin >> choice;
        system("cls"); // Очищення консолі, щоб не нагрмоджувати консоль

        if (choice == 0) {
            break;  // Вихід або повернення в батьківське меню
        } else if (choice > 0 && choice <= static_cast<int>(items.size())) {
            items[choice - 1].action();  // Виклик функції для пункту
        } else {
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }
}
