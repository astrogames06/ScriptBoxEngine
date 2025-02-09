#include "Game/Game.hpp"

extern Game game;

namespace fs = std::filesystem;

std::vector<std::string> GetFileNamesInFolder(const std::string& folderPath) {
    std::vector<std::string> fileNames;

    if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                fileNames.push_back(entry.path().filename().string());
            }
        }
    }
    
    return fileNames;
}

std::vector<std::string> SplitString(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

Entity& GetEntityByName(const std::string& name)
{
    for (Entity& entity : game.entities) {
        if (entity.name == name) {
            return entity;
        }
    }
    auto it = std::find_if(game.killed_entities.begin(), game.killed_entities.end(), [&name](const Entity& item) {
        return item.name == name;
    });

    if (it == game.killed_entities.end()) {
        std::string err = "! ENTITY " + name + " NOT FOUND !";
        auto er_it = std::find_if(game.Errors.begin(), game.Errors.end(), [&err](std::string& item) {
            return err == item;
        });
        if (it != game.killed_entities.end())
        {
            Error(err);
        }
    }
    static Entity default_entity;
    default_entity.name = name;
    return default_entity;
}

int CountStringsInVector(std::vector<std::string>& v, std::string& s)
{
    int i = 0;
    for (std::string& fs : v)
    {
        if (fs == s) i++;
    }

    return 0;
}