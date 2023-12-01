#include <iostream>
#include <string>
#include "functions.h"

int main() {
	const int NUM = 8;          //マスの数
	char** data = nullptr;      //入力されたデータ
	char** temp = nullptr;      //回転したデータを作る場所

	allocatingMemory(NUM, data);    //動的確保
	allocatingMemory(NUM, temp);

	loadData(NUM, data, "data.txt");
	draw(NUM, data);

	while (1) {
		std::cout << "Rで左回転、-Rで右回転、EXITで終了します" << std::endl;
		std::string command;
		std::cin >> command;
		if (command == "R" || command == "r") {
			rotate(NUM, data, temp, 1);
			draw(NUM, data);
		}
		else if (command == "-R" || command == "-r") {
			rotate(NUM, data, temp, -1);
			draw(NUM, data);
		}
		else if (command == "EXIT" || command == "exit" || command == "e") {
			break;
		}
	}

	freeingMemory(NUM, temp);       //解放
	freeingMemory(NUM, data);
	return 0;
}