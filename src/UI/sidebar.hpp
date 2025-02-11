#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <raylib.h>
#include <string>
#include <iostream>
#include <algorithm>

#include "../Game/Game.hpp"
#include "../utils.hpp"

#include "ui.hpp"

extern Game game;
bool dropdownActive = false;
int activeOption = -1;           
std::string options = "";

std::string entity_name_input_buffer;
bool showMessageBox = false;
int messageBoxResult = -1;

std::string gui_text_box_message = "ENTER ENTITY NAME!";

void InitSideBar()
{
    for (std::string& path : GetFileNamesInFolder("assets/sprites"))
	{
		options += path + ";";
	}
	options.resize(options.size()-1);
}

void DrawSideBar()
{
	if (!game.run)
	{
		DrawRectangle(0, 0, 200, game.HEIGHT, GRAY);
		for (int i = 0; i < game.entities.size(); i++)
		{
			if (game.entities[i].name != "Mouse")
			{
				Entity& v = game.entities[i];
				if (GuiButtonRounded({10, (float)(i-game.pre_entities)*55+75, 180, 45}, v.name.c_str(), 10.f, 50))
				{
					game.entities.erase(game.entities.begin() + i);
				}
			}
		}

		if (GuiDropdownBox((Rectangle){ 10, 20, 180, 45 }, options.c_str(), &activeOption, dropdownActive))
		{
			if (activeOption != -1)
			{
				showMessageBox = true; 
			}
		}
		if (GuiButton({10, 20, 180, 45}, "Add Entity")) dropdownActive = !dropdownActive;

		if (showMessageBox)
		{
			int textbox = GuiTextInputBox({
				(float)game.WIDTH/2-280/2,
				(float)game.HEIGHT/2-280/2, 280, 280
			}, "ENTITY NAME", gui_text_box_message.c_str(), "ENTER;CANCEL", &entity_name_input_buffer[0], 20, nullptr);
			if (textbox == 1)
			{
				if (activeOption != -1)
				{
					std::string file_name = SplitString(options, ";")[activeOption];
					Texture2D entity_tex = LoadTexture(("assets/sprites/" + file_name).c_str());

					auto it = std::find_if(game.entities.begin(), game.entities.end(), [](Entity& obj) {
						return obj.name == &entity_name_input_buffer[0];
					});

					if (it != game.entities.end())
					{
						gui_text_box_message = "ENTER ENTITY NAME!\n! NAME TAKEN !";
					}
					else
					{
						game.AddEntity(entity_tex, game.WIDTH/2-entity_tex.width/2, game.HEIGHT/2-entity_tex.height/2, &entity_name_input_buffer[0], file_name);
						showMessageBox = false; 
						activeOption = -1;
						entity_name_input_buffer.clear();
						gui_text_box_message = "ENTER ENTITY NAME!";
					}
				}
			}
			else if (textbox == 2) { showMessageBox = false; activeOption = -1; }
		}
	}
}

#endif