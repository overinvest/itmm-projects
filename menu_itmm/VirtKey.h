#pragma once
class VirtKey
{
public:
	VirtKey(int vkey);
	void update_key();
	int prev_value;
	int value;
	int is_released_buff;
	int is_released;
	int is_held;
	int is_toggled;
	int vkey;
};

