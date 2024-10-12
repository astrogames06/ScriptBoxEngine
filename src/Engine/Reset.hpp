#ifndef RESET_H
#define RESET_H

#include "../Game/Game.hpp"
#include "../Entity/Entity.hpp"

extern Game game;

bool reset_once = false;

void Reset()
{
    if (!reset_once)
    {
        reset_once = true;

        for (Entity& entity : game.killed_entities)
        {
            std::cout << entity.name << '\n';
            auto it = std::find_if(game.entities.begin(), game.entities.end(), [&entity](Entity& obj) {
                return obj.name == entity.name;
            });
            if (it == game.entities.end())
            {
                game.AddEntity(entity.texture, entity.original_x, entity.original_y, entity.name, entity.texture_name);
            }
        }
        game.killed_entities.clear();

        game.entities.erase(std::remove_if(game.entities.begin(), game.entities.end(),
        [](Entity& entity) {
            entity.x = entity.original_x;
            entity.y = entity.original_y;
            entity.angle = 0.f;

            return entity.in_run;
        }),
        game.entities.end());
        // game.lua = sol::state();
        // std::cout << "RESET LUA\n";
    }
}

#endif