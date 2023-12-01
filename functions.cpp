#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "functions.h"

using namespace std;

bool loadData(int num, char**& data, const char* fileName)
{
	ifstream ifs(fileName);
	if (!ifs) {
		cout << "ファイルを開けませんでした" << endl;
		return false;
	}

	string buf;
	for (int readLine = 0; readLine < num; readLine++) {
		if (ifs.eof()) {
			cout << "入力データの行数が不正です" << endl;
			return false;
		}
		getline(ifs, buf);
		if (buf.size() == num) {
			for (int i = 0; i < num; i++) {
				data[readLine][i] = buf[i];
			}
		}
		else {
			cout << "入力データの列数が不正です" << endl;
			return false;
		}
	}
	cout << "ロード完了" << endl << endl;
	return true;
}

void allocatingMemory(int num, char**& data)
{
	data = new char* [num];
	for (int i = 0; i < num; i++) {
		data[i] = new char[num];
	}
}

void freeingMemory(int num, char**& data)
{
	for (int i = 0; i < num; i++) {
		delete data[i];
	}
	delete[] data;
}

void draw(int num, char**& data)
{
	for (int row = 0; row < num; row++) {
		for (int col = 0; col < num; col++) {
			cout << (data[row][col] == '1' ? "＊" : "　");
		}
		cout << endl;
	}
}

void rotate(int num, char**& data, char**& temp, int rotateMode)
{
	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			temp[x][num - 1 - y] = data[y][x];
		}
	}
	for (int row = 0; row < num; row++) {
		for (int col = 0; col < num; col++) {
			data[row][col] = temp[row][col];
		}
	}
}
