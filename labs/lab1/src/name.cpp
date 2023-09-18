#include <iostream>
#include "name.hpp"

std::string get_name()
{
    std::cout << "What's your name?" << std::endl;
    std::string name;
    std::cin >> name;
    return name;
}