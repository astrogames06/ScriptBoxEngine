#include "Console.hpp"
#include "../Game/Game.hpp"

extern Game game;

void Error(std::string info)
{
    game.Errors.push_back(info);
}