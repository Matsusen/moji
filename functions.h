#pragma once

bool loadData(int num, char**& data, const char* fileName);             //txt�t�@�C������f�[�^�����[�h
void allocatingMemory(int num, char**& data);                           //���I�m��
void freeingMemory(int num, char**& data);                              //���
void draw(int num, char**& data);                                       //�\��
void rotate(int num, char**& data, char**& temp, int rotateMode = 1);   //data�̒��g����]���������̂ɏ���������