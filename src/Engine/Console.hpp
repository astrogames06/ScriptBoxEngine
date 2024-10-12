#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

#include "../Game/Game.hpp"

extern Game game;

inline void Error(std::string info)
{
    game.Errors.push_back(info);
}

#endif