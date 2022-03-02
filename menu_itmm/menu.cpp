#include <Windows.h>
#include <iostream>
#include "menu.h"
#include "items.h"
#include "Functions.h"
#include "VirtKey.h"

namespace menu {
	std::vector<items> menu_items;
}

void clear() {
	system("cls"); // ������� �����
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void menu::draw_menu(int selected_idx) {
	clear();

	std::cout << "Menu: " << std::endl;

	for (int i = 0; i < menu::menu_items.size(); i++) {
		items item = menu::menu_items.at(i);
		if (i == selected_idx) {
			SetColor(0, 15);
			std::cout << i + 1 << ". " << item.name;
			SetColor(15, 0);
			std::cout << "\n";
		}
		else {
			std::cout << i + 1 << ". " << item.name << std::endl;
		}
	}

	std::cout << "����� esc ���� ������ ������� ����" << std::endl;
}

void menu::show_items() {
	int start_idx = 0;

	menu::draw_menu(start_idx);

	bool item_selected = false;

	VirtKey ENTER = VirtKey(VK_RETURN);
	VirtKey UP = VirtKey(VK_UP);
	VirtKey DOWN = VirtKey(VK_DOWN);
	VirtKey ESC = VirtKey(VK_ESCAPE);

	do {

		UP.update_key();
		DOWN.update_key();
		ESC.update_key();
		ENTER.update_key();

		if (UP.is_released) {
			start_idx--;

			if (start_idx < 0) {
				start_idx = menu::menu_items.size() - 1;
			}

			menu::draw_menu(start_idx);
		}

		if (DOWN.is_released) {
			start_idx++;

			if (start_idx > menu::menu_items.size() - 1) {
				start_idx = 0;
			}

			menu::draw_menu(start_idx);
		}

		if ( ENTER.is_held && !ENTER.is_released ) {
			item_selected = true;
		}

	} while (!(ESC.is_released || item_selected));
	clear();

	UP.update_key();
	DOWN.update_key();
	ESC.update_key();
	ENTER.update_key();

	bool should_show = false;

	if (item_selected) {
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		menu::show_item(start_idx);
	}
}

void menu::show_item(int idx) {
	VirtKey ESC = VirtKey(VK_ESCAPE);

	clear();
	menu::menu_items.at(idx).callback();

	std::cout << "������� ESC ����� ����� �� ���������" << std::endl;

	do {
		ESC.update_key();
	} while (!(ESC.is_released));
	ESC.update_key();

	menu::show_items();
}

void menu::init()
{

	menu::create_item("����� n-�����", Algoritm1);
	menu::create_item("����� ������������ �������� ������� � ������������ ��� ����� � �������", Algoritm2);
	menu::create_item("����� �������� ������� �� ��������� �������� � ������������� ������ �������", Algoritm3);
	menu::create_item("�������� �����", Algoritm4);
	menu::create_item("�������� �����", Algoritm5);
	menu::create_item("������ ��� ����������", Algoritm6);
	menu::create_item("������ ��� ���������� + �������", Algoritm7);
	menu::create_item("������ ��� ���������� + ��������������", Algoritm8);
	menu::create_item("��������� ������ �� �����", Algoritm9);
	menu::create_item("��������� ������ �� ����� � �������������", Algoritm10);

	std::cout << "Items count: " << menu::menu_items.size() << " Address: " << &menu::menu_items << std::endl;

	menu::show_items();
}

items menu::create_item(std::string name, void (*callback)(void))
{
    items new_item(name, callback);

	menu::menu_items.push_back(new_item);
    return new_item;
}
