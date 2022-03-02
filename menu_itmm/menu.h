#include <string>
#include <vector>
#include "items.h"

namespace menu {
	items create_item(std::string name, void (*callback)(void));
	void show_items();
	void show_item(int idx);
	void draw_menu(int selected_idx);
	void init();
};