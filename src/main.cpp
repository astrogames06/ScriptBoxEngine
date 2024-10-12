#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "Game/Game.hpp"
#include "UI/ui.hpp"

#include "utils.hpp"

#include "Engine/Transformation.hpp"
#include "Engine/Setup.hpp"

#include "SaveLoadData/SaveLoadData.hpp"

Game game;

void UpdateDrawFrame();

int main(void)
{
	InitWindow(game.WIDTH, game.HEIGHT, "raylib [core] example - basic window");
	game.WIDTH = GetScreenWidth();
	game.HEIGHT = GetScreenHeight();
	//ToggleFullscreen();

	LoadData();
	InitUI();

	LuaEngineSetup();

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	SaveData();
	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	if (!game.init_lua && game.run)
	{
		game.init_lua = true;
		LuaEngineInit();
	}

	game.Update();

	if (game.run)
		LuaEngineUpdate();

	BeginDrawing();
	
	ClearBackground(game.background_color);

	game.Draw();

	if (game.run)
		LuaEngineDraw();

	DrawUI();

	EndDrawing();
}