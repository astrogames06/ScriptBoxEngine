#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <string>

#include "../Entity/Entity.hpp"
#include "../utils.hpp"

bool Collision(std::string nameA, std::string nameB)
{
    Entity& entityA = GetEntityByName(nameA);
    Entity& entityB = GetEntityByName(nameB);

    return CheckCollisionRecs(
        Rectangle {
            (float)entityA.x,
            (float)entityA.y,
            (float)entityA.texture.width,
            (float)entityA.texture.height
        },
        Rectangle {
            (float)entityB.x,
            (float)entityB.y,
            (float)entityB.texture.width,
            (float)entityB.texture.height
        }
    );
}

void DefineCollisions()
{
    game.lua.set_function("Collision", Collision);
}

#endif