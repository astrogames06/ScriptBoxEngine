#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <raylib.h>
#include <algorithm>

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"
#include "../utils.hpp"

extern Game game;

void InitEntity(std::string name, std::string texture, int x, int y)
{
    game.AddEntity(LoadTexture(("assets/sprites/" + texture).c_str()), x, y, name, texture);
}

void Kill(std::string name)
{
    Entity& entity = GetEntityByName(name);

    if (!entity.in_run)
    {
        game.killed_entities.push_back(entity);
    }

    game.entities.erase(std::remove_if(game.entities.begin(), 
                              game.entities.end(),
                              [&](const Entity& entity) { return entity.name == name; }), 
               game.entities.end());
}

void DefineEntityFunctions()
{
    game.lua.set_function("InitEntity", InitEntity);
    game.lua.set_function("Kill", Kill);
}

#endif