#include <Windows.h>
#include "VirtKey.h"

VirtKey::VirtKey(int vkey) {
	this->prev_value = 0;
	this->value = 0;
	this->is_released_buff = 0;
	this->is_released = 0;
	this->is_held = 0;
	this->is_toggled = 0;
	this->vkey = vkey;
}

void VirtKey::update_key() {
	this->prev_value = this->value;
	this->value = GetAsyncKeyState(this->vkey);

	this->is_held = this->value < 0 ? 1 : 0;

	if (this->is_released_buff == 0 && this->is_released == 1) {
		this->is_released = 0;
		this->is_released_buff = 0;
	}

	if (this->is_held == 1 && this->is_released_buff == 0) {
		this->is_released_buff = 1;
	}

	if (this->is_released_buff == 1 && this->is_released == 0 && this->is_held == 0) {
		this->is_released = 1;
		this->is_released_buff = 0;
	}

	this->is_toggled = GetKeyState(this->vkey) & 1;
}