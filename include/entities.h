// header file with entities declaration

#include "../include/food.hpp"
#include "../include/snake.hpp"
#include "../include/settings.hpp"

using namespace food;
using namespace snake;
using namespace settings;

#ifndef ENTITIES_HPP
#define ENTITIES_HPP

Food seed;
Head lead;
Body foll[QUAD - 1];

#endif