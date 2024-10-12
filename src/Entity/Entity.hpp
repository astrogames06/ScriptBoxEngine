#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <string>

class Entity
{
public:
    Texture2D texture;
    std::string texture_name;
    int x, y = 0;
    int original_x, original_y = 0;
    float angle = 0;
    std::string name;
    bool in_run = false;

    void Update();
    void Draw();
};

#endif