#include <iostream>

struct Extrusor {
	char identificador;
	int temperatura;
};

void almacenarExtrusores(int numExtr, Extrusor* listaExtrusores) {
	for (int i = 0; i < numExtr; i++) {
		std::cout << "Asigne una letra al extrusor " << i + 1 << ": ";
		std::cin >> listaExtrusores[i].identificador;
		std::cout << "\nA que temperatura se debe precalentar el extrusor " << i + 1 << "\n";
		std::cin >> listaExtrusores[i].temperatura;
	}
}

void imprimirExtrusores(int numExtr, Extrusor* listaExtrusores) {
	for (int i = 0; i < numExtr; i++) {
		std::cout << "El extrusor " << listaExtrusores[i].identificador << " a " << listaExtrusores[i].temperatura << "\n";
	}
}

int main() {
	int numExtr;

	std::cout << "Con cuantos extrusores estas trabajando?" << std::endl;
	std::cin >> numExtr;
	if (numExtr <= 0) {
		std::cout << "Entonces no hay nada que pueda hacer!" << std::endl;
		return 0;
	}
	Extrusor* listaExtrusores = new Extrusor[numExtr];

	almacenarExtrusores(numExtr, listaExtrusores);
	imprimirExtrusores(numExtr, listaExtrusores);

	delete[] listaExtrusores;

	return 0;
}