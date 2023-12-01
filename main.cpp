#include <iostream>
#include "functions.h"

//using namespace std;

int main() {
	const int NUM = 8;			//�}�X�̐�
	char** data = nullptr;		//���͂��ꂽ�f�[�^
	char** temp = nullptr;		//��]�����f�[�^�����ꏊ

	allocatingMemory(NUM, data);	//���I�m��
	allocatingMemory(NUM, temp);

	loadData(NUM, data, "data.txt");
	draw(NUM, data);

	for (int i = 0; i < 4; i++) {
		rotate(NUM, data, temp, -1);
		draw(NUM, data);
	}

	freeingMemory(NUM, temp);		//���
	freeingMemory(NUM, data);
	return 0;
}