#include <iostream>
#include "functions.h"

//using namespace std;

int main() {
	const int NUM = 8;			//マスの数
	char** data = nullptr;		//入力されたデータ
	char** temp = nullptr;		//回転したデータを作る場所

	allocatingMemory(NUM, data);	//動的確保
	allocatingMemory(NUM, temp);

	loadData(NUM, data, "data.txt");
	draw(NUM, data);

	for (int i = 0; i < 4; i++) {
		rotate(NUM, data, temp, -1);
		draw(NUM, data);
	}

	freeingMemory(NUM, temp);		//解放
	freeingMemory(NUM, data);
	return 0;
}