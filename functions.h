#pragma once

bool loadData(int num, char**& data, const char* fileName);             //txtファイルからデータをロード
void allocatingMemory(int num, char**& data);                           //動的確保
void freeingMemory(int num, char**& data);                              //解放
void draw(int num, char**& data);                                       //表示
void rotate(int num, char**& data, char**& temp, int rotateMode = 1);   //dataの中身を回転させたものに書き換える