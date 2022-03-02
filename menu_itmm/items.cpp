#include "items.h"
#include <string>
#include <iostream>

items::items(std::string name, void (*callback)(void)) {
	std::cout << name << " Successfully createad with description " << std::endl;
	this->callback = callback;
	this->name = name;
}