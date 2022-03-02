#pragma once
#include <string>

class items
{
public:
    items(std::string name, void (*callback)(void));
    void (*callback)(void);
    std::string name;
};

