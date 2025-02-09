#include "Transformation.hpp"
#include "../Game/Game.hpp"
#include "../utils.hpp"
#include <cmath>

extern Game game;

void SetPosition(std::string name, int x, int y)
{
    Entity& entity = GetEntityByName(name);
    entity.x = x;
    entity.y = y;
}

int GetX(std::string name)
{
    Entity& entity = GetEntityByName(name);
    return entity.x;
}

void SetX(std::string name, int x)
{
    Entity& entity = GetEntityByName(name);
    entity.x = x;
}

int GetY(std::string name)
{
    Entity& entity = GetEntityByName(name);
    return entity.y;
}

void SetY(std::string name, int y)
{
    Entity& entity = GetEntityByName(name);
    entity.y = y;
}

int GetWidth(std::string name)
{
    Entity& entity = GetEntityByName(name);
    return entity.texture.width;
}

void SetWidth(std::string name, int width)
{
    Entity& entity = GetEntityByName(name);
    entity.texture.width = width;
}

int GetHeight(std::string name)
{
    Entity& entity = GetEntityByName(name);
    return entity.texture.height;
}

void SetHeight(std::string name, int height)
{
    Entity& entity = GetEntityByName(name);
    entity.texture.height = height;
}

void Move(std::string name, int x, int y)
{
    Entity& entity = GetEntityByName(name);
    entity.x += x;
    entity.y += y;
}

void Angle(std::string name, float angle)
{
    Entity& entity = GetEntityByName(name);
    entity.angle = angle;
}

void LookAt(std::string nameA, std::string nameB)
{
    Entity& entityA = GetEntityByName(nameA);
    Entity& entityB = GetEntityByName(nameB);

    entityA.angle = atan2f(entityA.y - entityB.y, entityA.x - entityB.x) * RAD2DEG;
}

void DefineTransformation()
{
    game.lua.set_function("SetPosition", SetPosition);
    game.lua.set_function("GetX", GetX);
    game.lua.set_function("SetX", SetX);
    game.lua.set_function("GetY", GetY);
    game.lua.set_function("SetY", SetY);
    game.lua.set_function("GetWidth", GetWidth);
    game.lua.set_function("SetWidth", SetWidth);
    game.lua.set_function("GetHeight", GetHeight);
    game.lua.set_function("SetHeight", SetHeight);
    game.lua.set_function("rec", DrawRectangleLines);
    game.lua.set_function("Move", Move);
    game.lua.set_function("LookAt", LookAt);
    game.lua.set_function("Angle", Angle);
}
