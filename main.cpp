#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	const int NUM = 8;
	char** data = nullptr;
	allocatingMemory(NUM, data);
	cout << data[0][0] << endl;

	//loadData(NUM, data, "data.txt");

	//freeingMemory(NUM, data);
	return 0;
}