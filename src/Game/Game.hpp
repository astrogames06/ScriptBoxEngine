#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <sol/sol.hpp>

#include <unordered_set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../Entity/Entity.hpp"
#include "../Engine/Console.hpp"
#include "../utils.hpp"

class Game
{
public:
    int WIDTH = GetScreenWidth();
    int HEIGHT = GetScreenHeight();
    std::string title;
    bool run;

    Color background_color = WHITE;

    std::vector<Entity> entities;
    std::vector<Entity> killed_entities;
    int pre_entities;
    Entity* selected_entity;
    bool entity_selected;

    std::vector<std::string> Errors;

    sol::state lua;
    bool init_lua = false;

    void Init();
    void Update();
    void Draw();

    void AddEntity(Texture2D texture, int x, int y, std::string name, std::string texture_name);
};

#endif