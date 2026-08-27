#include <iostream>

void duplicarPuntos(int* ptr) {
	*ptr = *ptr * 2;
}

int main() {
	int puntos = 10;
	int* ptrPuntos = &puntos;
	
	duplicarPuntos(ptrPuntos);

	std::cout << puntos;
}