#include <iostream>
#include <string>
#include "functions.h"

int main() {
	const int NUM = 8;          //�}�X�̐�
	char** data = nullptr;      //���͂��ꂽ�f�[�^
	char** temp = nullptr;      //��]�����f�[�^�����ꏊ

	allocatingMemory(NUM, data);    //���I�m��
	allocatingMemory(NUM, temp);

	loadData(NUM, data, "data.txt");
	draw(NUM, data);

	while (1) {
		std::cout << "R�ō���]�A-R�ŉE��]�AEXIT�ŏI�����܂�" << std::endl;
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

	freeingMemory(NUM, temp);       //���
	freeingMemory(NUM, data);
	return 0;
}