#include "Entity.hpp"

void Entity::Update()
{

};

void Entity::Draw()
{
    // DrawTexture(this->texture, this->x, this->y, WHITE);
    DrawTexturePro(this->texture,
        {0, 0, (float)this->texture.width, (float)this->texture.height},
        {(float)x, (float)y, (float)this->texture.width, (float)this->texture.height},
        {(float)this->texture.width/2, (float)this->texture.height/2},
        this->angle,
        WHITE
    );

    // DrawRectanglePro(
    //     {(float)x, (float)y, (float)this->texture.width, (float)this->texture.height},
    //     {(float)this->texture.width/2, (float)this->texture.height/2},
    //     this->angle,
    //     GREEN
    // );
}