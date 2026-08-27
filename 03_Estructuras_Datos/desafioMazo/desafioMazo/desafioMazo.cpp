#include <iostream>

struct Carta {
	int poder = -1;
	char palo = '-';
};

void almacenarMazo(int numCartas, Carta* mazo) {
	for (int i = 0; i < numCartas; i++) {
		if (mazo[i].poder == -1) {
			do {
				std::cout << "\nIndique el poder de la carta n" << i + 1 << ": ";
				std::cin >> mazo[i].poder;
				std::cin.ignore();
				std::cout << "\nBien, ahora ingrese el palo ('A' Aguijon, 'H' Hechizo o 'C' Caparazon): ";
				std::cin >> mazo[i].palo;
			} while (mazo[i].palo != 'A' && mazo[i].palo != 'H' && mazo[i].palo != 'C');
		}
	}
}

bool filtrarMazo(int numCartas, int filtro, Carta* mazo) {
	bool cartaFiltrada = false;
	for (int i = 0; i < numCartas; i++) {
		if (mazo[i].poder <= filtro) {
			mazo[i].poder = -1;
			mazo[i].palo = '-';
			cartaFiltrada = true;
		}
	}
	if (cartaFiltrada) {
		std::cout << "Algunas cartas fueron eliminadas por ser de excesivo poco poder, vuelva a ingresar esos valores";
		return true;
	}
	return false;
}

void imprimirMazo(int numCartas, Carta* mazo) {
	std::cout << "\nBien, el mazo creado entonces es: " << std::endl;
	for (int i = 0; i < numCartas; i++) {
		std::cout << mazo[i].palo << " " << mazo[i].poder << "\n";
	}
}

int main() {
	int numCartas, filtro;

	std::cout << "Bienvenido al creador de mazos, cuantas cartas va a tener tu mazo?" << std::endl;
	std::cin >> numCartas;
	if (numCartas <= 0) {
		std::cout << "No hay nada para imprimir entonces!";
		return 0;
	}
	Carta* mazo = new Carta[numCartas];
	std::cout << "Cual es el minimo de poder que deben tener todas las cartas?" << std::endl;
	std::cin >> filtro;

	do{
		almacenarMazo(numCartas, mazo);
	} while (filtrarMazo(numCartas, filtro, mazo));
	imprimirMazo(numCartas, mazo);

	delete[] mazo;
	return 0;
}