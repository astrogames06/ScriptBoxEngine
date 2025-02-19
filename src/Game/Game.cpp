#include "Game.hpp"
#include "../Engine/Transformation.hpp"

extern bool showMessageBox;

void Game::Init()
{
    AddEntity(Texture{}, GetMouseX(), GetMouseY(), "Mouse", "");

    pre_entities = entities.size();
}

void Game::Update()
{
    for (Entity& entity : entities)
    {
        entity.Update();
        if (entity.name == "Mouse") { entity.x = GetMouseX(); entity.y = GetMouseY(); }

        if (!run && !showMessageBox)
        {
            if (CheckCollisionPointRec(
                GetMousePosition(),
                Rectangle{(float)entity.x, (float)entity.y, (float)entity.texture.width, (float)entity.texture.height}
            ) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if (!entity_selected)
                {
                    selected_entity = &entity;
                    entity_selected = true;
                }
            }

            if (entity_selected)
            {
                selected_entity->x = GetMouseX()-selected_entity->texture.width/2;
                selected_entity->y = GetMouseY()-selected_entity->texture.height/2;
                selected_entity->original_x = selected_entity->x;
                selected_entity->original_y = selected_entity->y;
            }

            if (selected_entity != NULL)
            {
                DrawRectangleLines(
                    selected_entity->x,
                    selected_entity->y,
                    selected_entity->texture.width,
                    selected_entity->texture.height,
                    GREEN
                );

                // Left
                DrawCircle(
                    selected_entity->x-10,
                    selected_entity->y+selected_entity->texture.height/2,
                    5.f,
                    RED
                );

                // Right
                DrawCircle(
                    selected_entity->x+selected_entity->texture.width+10,
                    selected_entity->y+selected_entity->texture.height/2,
                    5.f,
                    GREEN
                );

                // Top
                DrawCircle(
                    selected_entity->x+selected_entity->texture.width/2,
                    selected_entity->y-10,
                    5.f,
                    BLUE
                );

                // Top
                DrawCircle(
                    selected_entity->x+selected_entity->texture.width/2,
                    selected_entity->y+selected_entity->texture.height+10,
                    5.f,
                    YELLOW
                );
            }

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                entity_selected = false;
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !CheckCollisionPointRec(
                GetMousePosition(),
                Rectangle{(float)entity.x, (float)entity.y, (float)entity.texture.width, (float)entity.texture.height})
            )
            {
                selected_entity = NULL;
            }
        }
    }
    for (std::string& str : Errors)
    {
        if (CountStringsInVector(Errors, str) < 2)
            std::cout << "\033[1;31m" << str << "\033[0m" << '\n';
    }
}

void Game::Draw()
{
    for (Entity& entity : entities)
    {
        DrawText(std::to_string(entity.in_run).c_str(), entity.x, entity.y, 20, BLUE);
        entity.Draw();
    }
}

void Game::AddEntity(Texture2D texture, int x, int y, std::string name, std::string texture_name)
{
    auto it = std::find_if(entities.begin(), entities.end(), [&](Entity& obj) {
        return obj.name == name;
    });

    if (it == entities.end())
    {
        Entity new_entity;
        new_entity.texture = texture;
        new_entity.x = x;
        new_entity.y = y;
        new_entity.original_x = x;
        new_entity.original_y = y;
        new_entity.name = name;
        new_entity.texture_name = texture_name;

        new_entity.in_run = run;
        entities.push_back(new_entity);
    }
    else
    {
        Error("! ENTITY NAME (" + name + ") IS ALREADY A CHOSEN NAME !");
    }
}