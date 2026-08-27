#include <iostream>

void almacenarPesos(int numCamiones, int* ptrCamiones) {
	for (int i = 0; i < numCamiones; i++) {
		std::cout << "Cuanto peso exactamente lleva el camion " << i+1 << "?\n";
		std::cin >> ptrCamiones[i];
	}
}

int sumarPesos(int numCamiones, int* ptrCamiones) {
	int pesoTotal = 0;
	for (int i = 0; i < numCamiones; i++) {
		pesoTotal = pesoTotal + ptrCamiones[i];
	}
	return pesoTotal;
}

int main() {
	int numCamiones;

	std::cout << "Hola Supervisor! Cuantos camiones van a ingresar hoy?" << std::endl;
	std::cin >> numCamiones;
	if (numCamiones <= 0) {
		std::cout << "Perfecto! No hay nada que hacer!" << std::endl;
		return 0;
	}
	int* ptrCamiones = new int[numCamiones];

	almacenarPesos(numCamiones, ptrCamiones);

	std::cout << "La cantidad de peso total de todos los camiones es: " << sumarPesos(numCamiones, ptrCamiones);
	delete[] ptrCamiones;

	return 0;
}