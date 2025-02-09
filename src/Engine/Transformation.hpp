#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <string>

void SetPosition(std::string name, int x, int y);
int GetX(std::string name);
void SetX(std::string name, int x);
int GetY(std::string name);
void SetY(std::string name, int y);
int GetWidth(std::string name);
void SetWidth(std::string name, int width);
int GetHeight(std::string name);
void SetHeight(std::string name, int height);
void Move(std::string name, int x, int y);
void Angle(std::string name, float angle);
void LookAt(std::string nameA, std::string nameB);
void DefineTransformation();

#endif
