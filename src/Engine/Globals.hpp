#ifndef GLOBALS_H
#define GLOBALS_H

#include "../Game/Game.hpp"

extern Game game;

sol::function init_func;
sol::function update_func;
sol::function draw_func;

void DefineGlobals()
{
    game.lua["WIDTH"] = game.WIDTH;
    game.lua["HEIGHT"] = game.HEIGHT;

    init_func = game.lua["Init"];
    update_func = game.lua["Update"];
    draw_func = game.lua["Draw"];
}

#endif