// menu.h
#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <functional>

class MenuItem {
public:
    std::string title;
    std::function<void()> action;  // Використовуємо std::function

    MenuItem(std::string t, std::function<void()> a);
};

class Menu {
private:
    std::vector<MenuItem> items;
    std::string menuTitle;
    Menu* parentMenu;  // Вказівник на батьківське меню

public:
    Menu(std::string title, Menu* parent = nullptr);

    void addItem(std::string title, std::function<void()> action);
    void display();
    void handleInput();
};

#endif
