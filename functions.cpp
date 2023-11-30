#include <iostream>
#include <fstream>
#include <string>
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
	cout << "ロード完了" << endl;
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
