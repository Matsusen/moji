#pragma once

bool loadData(int num, char**& data, const char* fileName);
void allocatingMemory(int num, char**& data);
void freeingMemory(int num, char**& data);
void draw(int num, char**& data);
void rotate(int num, char**& data, char**& temp, int rotateMode = 0);