#ifndef SETUP_H
#define SETUP_H

#include "../Game/Game.hpp"
#include "Console.hpp"
#include "../utils.hpp"
#include "Functions.hpp"
#include "Transformation.hpp"
#include "Globals.hpp"
#include "Keys.hpp"

extern Game game;

void LuaEngineInit()
{
    if (init_func.valid())
        init_func();
    else
        Error("! NO UPDATE FUNCTION FOUND IN LUA SCRIPT !");
}

void LuaEngineSetup()
{
    // Load libraries
    game.lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::coroutine, sol::lib::string,
                       sol::lib::os, sol::lib::math, sol::lib::table, sol::lib::debug);

    // Load scripts
    // for (std::string& file_name : GetFileNamesInFolder("../Scripts"))
    // {
    //     game.lua.script_file(file_name);
    // }
    game.lua.script_file("src/Scripts/main.lua");

    // Entity
    game.lua.new_usertype<Entity>("Entity",
        "name", &Entity::name,
        "x", &Entity::x,
        "y", &Entity::y,
        "angle", &Entity::angle
    );
    game.lua.set_function("Entity", &GetEntityByName);

    // Globals
    DefineGlobals();

    // Entity Functions
    DefineEntityFunctions();

    // Transformation Functions
    DefineTransformation();

    // Keys and Key pressing functions
    LoadKeys();

    // Transformation
    DefineTransformation();
}

void LuaEngineUpdate()
{
    if (update_func.valid())
        update_func();
    else
        Error("! NO UPDATE FUNCTION FOUND IN LUA SCRIPT !");
}

void LuaEngineDraw()
{
    if (draw_func.valid())
        draw_func();
    else
        Error("! NO DRAW FUNCTION FOUND IN LUA SCRIPT !");
}

#endif