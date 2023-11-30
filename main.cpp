#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	const int NUM = 8;
	char** data = nullptr;
	allocatingMemory(NUM, data);

	loadData(NUM, data, "data.txt");
	draw(NUM, data);

	freeingMemory(NUM, data);
	return 0;
}