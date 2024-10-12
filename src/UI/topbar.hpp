#ifndef TOPBAR_H
#define TOPBAR_H

#include "../Game/Game.hpp"
#include "../Engine/Setup.hpp"
#include "../Engine/Reset.hpp"
#include "ui.hpp"

extern Game game;

std::string run_button_text;

bool info_checkbox;

void InitTopBar()
{
    run_button_text = "#119# RUN";
    info_checkbox = false;
}

int run_button_x = 280;

extern bool reset_once;

void DrawTopBar()
{
    if (!game.run)
    {
        run_button_x = 280;
        if (GuiButtonRounded({505, 20, 180, 45}, "#200# CODE", 10.f, 50))
        {
            system("code src/scripts");
        }

        GuiCheckBox({730, 20, 50, 50}, "INFO", &info_checkbox);
    }

    if (GuiButtonRounded({(float)run_button_x, 20, 180, 45}, run_button_text.c_str(), 10.f, 50))
    {
        if (!game.run)
        {
            game.run = true;
            run_button_text = "#132# STOP";
            reset_once = false;
        }
        else
        {
            game.run = false;
            run_button_text = "#119# RUN";
            Reset();
            game.init_lua = false;
            game.Errors.clear();
        }
    }
    if (info_checkbox)
    {
        DrawFPS(20, game.HEIGHT-80);

        std::string entity_text = "Entities: " + std::to_string(game.entities.size());
        DrawText(entity_text.c_str(), 20, game.HEIGHT-100, 20, GREEN);
    }

    if (game.run)
    {
        run_button_x = 10;
    }
}

#endif