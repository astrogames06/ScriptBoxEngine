#ifndef UI_H
#define UI_H

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include "sidebar.hpp"
#include "topbar.hpp"

void InitUI()
{
    InitSideBar();
    InitTopBar();
}

void DrawUI()
{
    DrawSideBar();
    DrawTopBar();
}

#endif