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
	cout << endl;
}

void rotate(int num, char**& data, char**& temp, int rotateMode)
{
	for (int y = 0; y < num; y++) {
		for (int x = 0; x < num; x++) {
			if (rotateMode == 1) {
				temp[num - 1 - x][y] = data[y][x];
			}
			else {
				temp[x][num - 1 - y] = data[y][x];
			}
		}
	}
	for (int row = 0; row < num; row++) {
		for (int col = 0; col < num; col++) {
			data[row][col] = temp[row][col];
		}
	}
	//----------------------------------------
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　0 ｜ 1 2 3 4
	// ーーーーー＊＊＊＊＊ー＞Ｘ
	// 　　　　1 ＊
	// 　　　　2 ＊＊＊＊
	// 　　　　3 ＊
	// 　　　　4 ＊
	// 　　　　　｜
	// 　　　　　Ｖ
	// 　　　　　Ｙ
	// 　　　　　　　　↓　　　　｜ 0 1 0｜
	// 　　　　　　　　↓回転行列｜-1 0 0｜を掛ける
	// 　　　　　　　　↓　　　　｜ 0 0 1｜
	// 　　　　　　　　↓(y軸が反転しているので回る方向が逆になる)
	// 　　　　　｜
	// 　　　 -4 ＊
	// 　　　 -3 ＊　＊
	// 　　　 -2 ＊　＊
	// 　　　 -1 ＊　＊
	// ーーーーー＊＊＊＊＊ー＞Ｘ
	// 　　　　0 ｜ 1 2 3 4
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　　Ｖ
	// 　　　　　Ｙ
	// 　　　　　　　　↓yに4 (num-1)を足す
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　　｜
	// 　　　　0 ｜ 1 2 3 4
	// ーーーーー＊ーーーーー＞Ｘ
	// 　　　　1 ＊　＊
	// 　　　　2 ＊　＊
	// 　　　　3 ＊　＊
	// 　　　　4 ＊＊＊＊＊
	// 　　　　　｜
	// 　　　　　Ｖ
	// 　　　　　Ｙ
	//----------------------------------------
}
