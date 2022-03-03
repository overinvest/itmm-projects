#include <locale.h>
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <Windows.h>
#include "menu.h"

void localize() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

int main()
{
	localize();
    std::cout << "Привет, если ты хочешь открыть меню нажми Enter" << std::endl;

	menu::init();

	return 0;
}

