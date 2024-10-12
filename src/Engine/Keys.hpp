#ifndef KEYS_H
#define KEYS_H

#include <raylib.h>

#include "../Game/Game.hpp"

extern Game game;

void LoadKeys()
{
    game.lua["KEY_A"] = KEY_A;
    game.lua["KEY_B"] = KEY_B;
    game.lua["KEY_C"] = KEY_C;
    game.lua["KEY_D"] = KEY_D;
    game.lua["KEY_E"] = KEY_E;
    game.lua["KEY_F"] = KEY_F;
    game.lua["KEY_G"] = KEY_G;
    game.lua["KEY_H"] = KEY_H;
    game.lua["KEY_I"] = KEY_I;
    game.lua["KEY_J"] = KEY_J;
    game.lua["KEY_K"] = KEY_K;
    game.lua["KEY_L"] = KEY_L;
    game.lua["KEY_M"] = KEY_M;
    game.lua["KEY_N"] = KEY_N;
    game.lua["KEY_O"] = KEY_O;
    game.lua["KEY_P"] = KEY_P;
    game.lua["KEY_Q"] = KEY_Q;
    game.lua["KEY_R"] = KEY_R;
    game.lua["KEY_S"] = KEY_S;
    game.lua["KEY_T"] = KEY_T;
    game.lua["KEY_U"] = KEY_U;
    game.lua["KEY_V"] = KEY_V;
    game.lua["KEY_W"] = KEY_W;
    game.lua["KEY_X"] = KEY_X;
    game.lua["KEY_Y"] = KEY_Y;
    game.lua["KEY_Z"] = KEY_Z;
    game.lua["KEY_SPACE"] = KEY_SPACE;
    game.lua["KEY_ENTER"] = KEY_ENTER;
    game.lua["KEY_ESCAPE"] = KEY_ESCAPE;
    game.lua["KEY_TAB"] = KEY_TAB;
    game.lua["KEY_BACKSPACE"] = KEY_BACKSPACE;
    game.lua["KEY_LEFT"] = KEY_LEFT;
    game.lua["KEY_RIGHT"] = KEY_RIGHT;
    game.lua["KEY_UP"] = KEY_UP;
    game.lua["KEY_DOWN"] = KEY_DOWN;
    game.lua["KEY_ZERO"] = KEY_ZERO;
    game.lua["KEY_ONE"] = KEY_ONE;
    game.lua["KEY_TWO"] = KEY_TWO;
    game.lua["KEY_THREE"] = KEY_THREE;
    game.lua["KEY_FOUR"] = KEY_FOUR;
    game.lua["KEY_FIVE"] = KEY_FIVE;
    game.lua["KEY_SIX"] = KEY_SIX;
    game.lua["KEY_SEVEN"] = KEY_SEVEN;
    game.lua["KEY_EIGHT"] = KEY_EIGHT;
    game.lua["KEY_NINE"] = KEY_NINE;
    game.lua["KEY_LEFT_SHIFT"] = KEY_LEFT_SHIFT;
    game.lua["KEY_RIGHT_SHIFT"] = KEY_RIGHT_SHIFT;
    game.lua["KEY_LEFT_CONTROL"] = KEY_LEFT_CONTROL;
    game.lua["KEY_RIGHT_CONTROL"] = KEY_RIGHT_CONTROL;
    game.lua["KEY_LEFT_ALT"] = KEY_LEFT_ALT;
    game.lua["KEY_RIGHT_ALT"] = KEY_RIGHT_ALT;
    game.lua["KEY_F1"] = KEY_F1;
    game.lua["KEY_F2"] = KEY_F2;
    game.lua["KEY_F3"] = KEY_F3;
    game.lua["KEY_F4"] = KEY_F4;
    game.lua["KEY_F5"] = KEY_F5;
    game.lua["KEY_F6"] = KEY_F6;
    game.lua["KEY_F7"] = KEY_F7;
    game.lua["KEY_F8"] = KEY_F8;
    game.lua["KEY_F9"] = KEY_F9;
    game.lua["KEY_F10"] = KEY_F10;
    game.lua["KEY_F11"] = KEY_F11;
    game.lua["KEY_F12"] = KEY_F12;

    // Functions
    game.lua.set_function("KeyDown", IsKeyDown);
    game.lua.set_function("KeyPressed", IsKeyPressed);
    game.lua.set_function("KeyUp", IsKeyUp);
}

#endif