#ifndef UTILS_H
#define UTILS_H

#include <filesystem>
#include <vector>
#include <string>

std::vector<std::string> GetFileNamesInFolder(const std::string& folderPath);

std::vector<std::string> SplitString(std::string s, std::string delimiter);

Entity& GetEntityByName(const std::string& name);

int CountStringsInVector(std::vector<std::string>& v, std::string& s);

#endif