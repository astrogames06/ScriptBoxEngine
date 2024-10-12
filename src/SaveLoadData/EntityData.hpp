#ifndef ENTITYDATA_H
#define ENTITYDATA_H

#include <fstream>

#include "../utils.hpp"
#include "../Game/Game.hpp"

extern Game game;

void LoadEntites()
{
    std::ifstream file("src/Data/entities.txt");
    std::string line;

    if (file.is_open()) {
        std::cout << "File Openeded\n";
        while (std::getline(file, line)) {
            std::vector<std::string> split_line = SplitString(line, " ");
            std::cout << "Line Read\n";
            game.AddEntity(LoadTexture(("assets/sprites/" + split_line[1]).c_str()), std::atoi(split_line[2].c_str()), std::atoi(split_line[3].c_str()), split_line[0], split_line[1]);
        }
        std::cout << "Closed File\n";
        file.close();
    } else {
        std::cerr << "Unable to open file.\n";
    }
}

void SaveEntities()
{
    std::ofstream file("src/Data/entities.txt", std::ios::trunc);
    if (file.is_open())
    {
        std::cout << "File has been reset (contents cleared).\n";
        file.close();
    } 
    else
    {
        std::cerr << "Unable to open file.\n";
    }

    file.open("src/Data/entities.txt", std::ios::app);
    if (file.is_open()) {
        for (Entity& entity : game.entities)
        {
            if (entity.name != "Mouse" && !entity.in_run)
                file << entity.name << " " << entity.texture_name << " " << entity.original_x << " " << entity.original_y << '\n';
        }
        file.close();
        std::cout << "Data appended to file successfully.\n";
    } else {
        std::cerr << "Unable to open file for appending.\n";
    }
}

#endif