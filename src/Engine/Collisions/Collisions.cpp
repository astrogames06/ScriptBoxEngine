#include "Collisions.hpp"

#include "../../Game/Game.hpp"
#include "../Transformation.hpp"

extern Game game;

bool Collision(std::string nameA, std::string nameB)
{
    Entity& entityA = GetEntityByName(nameA);
    Entity& entityB = GetEntityByName(nameB);

    return CheckCollisionRecs(
        Rectangle {
            (float)GetX(nameA),
            (float)GetY(nameA),
            (float)GetWidth(nameA),
            (float)GetHeight(nameA)
        },
        Rectangle {
            (float)GetX(nameB),
            (float)GetY(nameB),
            (float)GetWidth(nameB),
            (float)GetHeight(nameB)
        }
    );
}

void DefineCollisions()
{
    game.lua.set_function("Collision", Collision);
}